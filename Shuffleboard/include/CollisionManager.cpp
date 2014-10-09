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
	AxisAlignedBox puckBox = movingEntity->getWorldBoundingBox();	
	std::vector<Puck *> usedPucks = PuckManager::instance()->getUsedPucks();
	for ( std::vector<Puck *>::iterator curr = usedPucks.begin(); curr != usedPucks.end() && collided == false ; ++curr ) {
		// Complete this for loop...

	}
	return make_pair(collided, targetPuckName);	
}


/**
* Implements a "placeholder" collision response when originPuck has collided with targetPuck.
* The correct collision respose will be developed in tutorial 5.
*
* @param originPuck The colliding puck.
* @param targetPuck The puck on the receiving end of the collision (collidee).
*/

void CollisionManager::handleCollisions( Puck * originPuck, Puck * targetPuck ) {	
	Vector3 dir = originPuck->getDirection();
	dir.z *= -1;
	originPuck->setDirection( dir );
	
}

