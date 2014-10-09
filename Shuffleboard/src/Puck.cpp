#include "Puck.h"


Puck::Puck( Ogre::SceneManager *sceneMan, Ogre::String const & puckName, PuckType type ) : 
	mSceneMgr( sceneMan ),
	mForceKineticFriction( GameConstants::COEFF_KINETIC_FRICTION * GameConstants::MASS * GameConstants::GRAVITY ),
	mDeceleration( mForceKineticFriction / GameConstants::MASS ),	
	mAcceleration(0),
	mVelocity(0),
	mDirection(0,0,0),
	mPuckName(puckName),
	mIsVisible( false ),
	mPuckType( type ) {
	
    // Start here...
		Ogre::String puckMeshPath;
		if(type == YELLOWSTONE)
		{
			puckMeshPath = "YELLOWSTONE.mesh";
		}
		else	//type = REDSTONE
		{
			puckMeshPath = "REDSTONE.mesh";
		}

		mEntity = mSceneMgr->createEntity(puckName, puckMeshPath);
		mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("node"+mPuckName);

		mNode->scale(1.5,1.5,1.5);
		//mNode->rotate(Ogre::Vector3(0,1,0), Ogre::Radian(3.14f), Ogre::Node::TS_LOCAL);
		mNode->attachObject(mEntity);
		mNode->setPosition(0,0,1000);

		AxisAlignedBox box = mEntity->getWorldBoundingBox(true);
		Vector3 boxSize(box.getSize()); // get dimensions of bounding box
		mRadius = boxSize.x / 2;
		mRadius = mRadius - 0.1f;
}

void Puck::update( Ogre::Real const & timeSinceLastFrame ) {		

	/*
		If the puck is visible and its velocity is positive, we translate according to the direction vector mDirection (remember, this is currently 0,0,-1, so the puck moves away from the camera). 
		We multiply this vector by 2 values: 
			[1] GameConstants::UPDATE_GRANULARITY – again this number represents the frequency with which we call update(). 
			[2] mVelocity - the current velocity of the Puck, clearly larger values will translate the Puck by a greater amount every frame. 
	*/

	//only update if this puck is visible and moving
	if ( mIsVisible && mVelocity > 0 )
	{
		// Check for collision...		
		std::pair<bool, Ogre::String> result = CollisionManager::instance()->checkCollisions( mEntity );

		// If a collision occurred.
		if ( result.first == true ) {			

			//local string variable to hole name of colliding puck
			Ogre::String collideeName = result.second;

			//get pointer to colliding puck
			Puck * collidee = PuckManager::instance()->getPuckByName(collideeName);

			CollisionManager::instance()->handleCollisions(this, collidee);
		}

		//when node is yawed 180, TS_LOCAL switches z directions
		mNode->translate( mDirection * GameConstants::UPDATE_GRANULARITY * mVelocity, Ogre::Node::TS_PARENT);

		updateMotion();

	}
	else if ( mVelocity < 0 )
	{
		mVelocity = 0;
	}
}



void Puck::activate( Ogre::Vector3 const & pos ) {	
	
	mNode->setPosition(pos);
	mDirection.z = -1;
	mIsVisible = true;

}


void Puck::applyForce( Ogre::Real const & force ) {
	mVelocity = force/GameConstants::MASS;
}

// This method rotates the Puck to the direction it is travelling
void Puck::rotate() {		
	Ogre::Vector3 directionFacing = mNode->getOrientation() * Ogre::Vector3::UNIT_Z;
	if ((1.0f + directionFacing.dotProduct(mDirection)) < 0.0001f) {
			mNode->yaw(Ogre::Degree(180));
	}
	else {
		Ogre::Quaternion quat = directionFacing.getRotationTo(mDirection);
		mNode->rotate(quat);
	} 
}

void Puck::updateMotion() {
	mAcceleration = -mDeceleration;
	Ogre::Vector3 pos = this->getPosition();

	//add acceleration to objects velocity
	if ( Ogre::Math::IFloor(mVelocity * 10) > 0 ) {
		mVelocity = mVelocity + ( mAcceleration * GameConstants::UPDATE_GRANULARITY );

		// Check if puck is out of bounds.
		if ( pos.x < GameConstants::MIN_X || pos.x > GameConstants::MAX_X || pos.z < GameConstants::MIN_Z ) {
			removeFromBoard();
		}
	}
	else {
		//puck has stopped on the board.
		mVelocity = mAcceleration = 0;
		mDirection = Vector3(0,0,0);

		//if puck has stopped before the foul line.
		if ( pos.z > GameConstants::FOUL_LINE ) {
		removeFromBoard();
		}
	} 
}


void Puck::removeFromBoard() {
	mIsVisible = false;
	mNode->setPosition(0, 0, 100);
	mAcceleration = 0;
}


Ogre::String Puck::getName() const {
	return mPuckName;
}

Ogre::Vector3 Puck::getPosition() const {	
	return mNode->getPosition();	
}

Ogre::Vector3 Puck::getDirection() const {
	return mDirection;
}

Ogre::Real Puck::getVelocity() const {
	return mVelocity;
}

Puck::PuckType Puck::getPuckType() const {
	return mPuckType;
}


bool Puck::isVisible() const {
	return mIsVisible;
}

void Puck::setVelocity( Ogre::Real const & velocity ) {
	mVelocity = velocity;
}


void Puck::setDirection( Ogre::Vector3 const & dir ) {
	mDirection = dir;
	rotate();
}

Ogre::Entity * Puck::getEntity() const {
	return mEntity;
}

void Puck::setPosition( Ogre::Vector3 const & position ){
	mNode->setPosition(position);
}


Ogre::Real Puck::getRadius() const {
	return mRadius;
} 
