#include "CollisionManager.h"

CollisionManager * CollisionManager::mInstance = 0;

// Protected constructor
CollisionManager::CollisionManager( SceneManager * sceneMgr ) : mSceneMgr( sceneMgr ) {
}


CollisionManager * CollisionManager::instance(SceneManager * sceneMgr) {
	if (mInstance == 0)  {  
		mInstance = new CollisionManager( sceneMgr );
	}
    return mInstance;
}

/**
 * Checks for a collision between the supplied entity and the entity for each Puck in the used list.
 *
 *  @param movingEntity The entity that represents the moving puck.
 *  @returns a std::pair<bool, Ogre::String>, the bool indicates hit (true) or miss (false)....the String is the name of the entity
 *     that was intersected or an empty String if no entity was intersected.
 */

pair<bool,Ogre::String> CollisionManager::checkCollisions(  Entity const * const movingEntity ) {

	String targetPuckName = "";

	bool collided = false;

	AxisAlignedBox puckBox = movingEntity->getWorldBoundingBox(true);	

	std::vector<Puck *> usedPucks = PuckManager::instance()->getUsedPucks();

	for ( std::vector<Puck *>::iterator curr = usedPucks.begin(); curr != usedPucks.end() && collided == false ; ++curr ) {
		
		Puck *p = (*curr);
		Entity * pEntity = p->getEntity();

		if ( movingEntity != pEntity)
			if ( puckBox.intersects(pEntity->getWorldBoundingBox(true)))
			{
				collided = true;
				targetPuckName = pEntity->getName();
			}

	}

	return make_pair(collided, targetPuckName);	
}


void CollisionManager::handleCollisions( Puck * originPuck, Puck * targetPuck ) {	
	Ogre::Vector3 uOrigin, uTarget, nPlane;

	Ogre::Vector3 vOrigin;
	Ogre::Vector3 vTarget;

	uOrigin = originPuck->getVelocity() * originPuck->getDirection();
	uTarget = targetPuck->getVelocity() * targetPuck->getDirection();

	nPlane = targetPuck->getPosition() - originPuck->getPosition();
	float distance = nPlane.length();

	

	Ogre::Vector3 mtd = nPlane * ( (originPuck->getRadius() + targetPuck->getRadius() ) - distance ) / distance; 

	originPuck->setPosition((mtd * 0.5f) + originPuck->getPosition());
	targetPuck->setPosition(targetPuck->getPosition() - (mtd * 0.5f));

	nPlane.normalise();

	// Va = Ua – ( (1+e) / 2 ) * ( (Ua – Ub) . n ) * n 
	vOrigin = uOrigin - ( (1 + 0.9f) / 2 ) * ( (uOrigin - uTarget).dotProduct(nPlane)) * nPlane;
	// Vb = Ub + ( (1+e) / 2 ) * ( (Ua – Ub) . n ) * n
	vTarget = uTarget + ( (1 + 0.9f) / 2 ) * ( (uOrigin - uTarget).dotProduct(nPlane)) * nPlane;

	originPuck->setVelocity(vOrigin.length());
	targetPuck->setVelocity(vTarget.length());

	vOrigin.normalise();
	vTarget.normalise();

	originPuck->setDirection(vOrigin);
	targetPuck->setDirection(vTarget);
}