#include "Shuffleboard.h"

Shuffleboard * Shuffleboard::mInstance = 0;

//-------------------------------------------------------------------------------------
Shuffleboard::Shuffleboard( SceneManager *sceneMan ) :
	mSceneMgr( sceneMan ) {

	initialise();
}

//-------------------------------------------------------------------------------------
void Shuffleboard::initialise() {
	// Create the Shuffleboard.
	Entity * ent = mSceneMgr->createEntity("Shuffleboard", "Shuffleboard.mesh");
	SceneNode *node = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodeShuffleboard");
	node->attachObject( ent );	
	node->setPosition( 0, 0, 0);
	
	//create the arrow
	ent = mSceneMgr->createEntity("Arrow", "arrow.mesh");
	mArrow = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodeArrow");
	mArrow->attachObject( ent );
	mArrow->setPosition( 5, 4, 15 );
	mArrow->yaw( Ogre::Degree(90) ); 
}


//-------------------------------------------------------------------------------------
Shuffleboard * Shuffleboard::instance(SceneManager * sceneMgr ) {
	if (mInstance == 0)  {  
		mInstance = new Shuffleboard( sceneMgr );
	}
    return mInstance;
}

//-------------------------------------------------------------------------------------
void Shuffleboard::setArrowVisible(bool visible) {
	mArrow->setVisible(visible);
}

//-------------------------------------------------------------------------------------
void Shuffleboard::rotateArrow(OIS::MouseEvent const & e) {
	Ogre::Real xMovement = e.state.X.rel * 0.1f;

	//arrow intially faces in the +ve x direction
	Ogre::Vector3 directionFacing = mArrow->getOrientation() * Vector3::UNIT_X;

	Ogre::Vector3 straightAhead(0, 0, -1);
	Ogre::Degree angle = directionFacing.angleBetween(straightAhead);
	
	Ogre:Degree maxAngle = Ogre::Degree(GameConstants::MAX_ANGLE);
	
	if(angle < maxAngle	//if angle is withing maximum
		|| (directionFacing.x > 0 && xMovement < 0)		//if facing right and trying to move left
		|| (directionFacing.x < 0 && xMovement > 0))	//if facing left and trying to move right
	{
		mArrow->yaw(Ogre::Degree(xMovement * -1));
	}//end if
}

//-------------------------------------------------------------------------------------
void Shuffleboard::launchPuck() {
	Puck * puck = PuckManager::instance()->getNextPuck();
	if(puck!=0) {		
		//This gives us the correct x,y,z position for the puck launch at the top of the shuffleboard
		Ogre::Real centreX = ( GameConstants::MAX_X - GameConstants::MIN_X ) / 2 + GameConstants::MIN_X; 
		Ogre::Vector3 launchPos( centreX, GameConstants::LAUNCH_Y, GameConstants::LAUNCH_Z );

		puck->activate(launchPos);
		puck->setDirection(mArrow->getOrientation() * Vector3::UNIT_X);
		puck->applyForce( mForce );

		// Reset the force and the arrow orientation.
		mForce = 0;
		resetArrowOrientation();
	}//end if
}

//-------------------------------------------------------------------------
bool Shuffleboard::getInputForce() {
	bool getInputForce = true;

	mForce += ( Ogre::Math::Pow(1.5f, mForce ) * GameConstants::PUCK_FORCE_MULTIPLIER );

	if ( mForce >= GameConstants::MAX_FORCE ) {
  		getInputForce = false;
		mForce = GameConstants::MAX_FORCE;
	}

	return getInputForce;
}

//--------------------------------------------------------------------------------
void Shuffleboard::resetArrowOrientation() {
	Ogre::Vector3 direction = mArrow->getOrientation() * Vector3::UNIT_X;
	Ogre::Quaternion quat = direction.getRotationTo( Ogre::Vector3(0, 0, -1) );
	mArrow->rotate(quat);
} 

//--------------------
Ogre::Real Shuffleboard::getPuckForce() const {
	return mForce;
}