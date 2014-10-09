#include "PuckManager.h"

PuckManager * PuckManager::mInstance = 0;

PuckManager::PuckManager( Ogre::SceneManager *sceneMan, int pucks ) :
	mSceneMgr( sceneMan ), 
	mPucks( pucks ) {	
		createPucks(pucks);	  
}

void PuckManager::createPucks(int pucks) {
	int i = 0;
	for ( int i = 0; i < pucks ; i++ ) {
		if ( ( i % 2 ) == 0 ) {
			mFreePucks.push_back( new Puck( mSceneMgr, "Yellowstone" + Ogre::StringConverter::toString(i+1), Puck::YELLOWSTONE ) );
		}
		else {
			mFreePucks.push_back( new Puck( mSceneMgr, "Redstone" + Ogre::StringConverter::toString(i+1), Puck::REDSTONE ) );
		}
	}
}

void PuckManager::update( Ogre::Real const & timeSinceLastFrame ) {
	std::vector<Puck *>::iterator curr = mUsedPucks.begin();
	std::vector<Puck *>::iterator end = mUsedPucks.end();

	for ( ; curr != end ; ++curr ) {
		(*curr)->update( timeSinceLastFrame );
	}
}


// Get a puck from the free list.
// Warning...returns 0 if no more pucks available.
Puck * PuckManager::getNextPuck() {
	Puck * puck = 0;			// returns 0 if no free pucks available.
	
	//if at least one puck free
	if( mFreePucks.size() > 0 )
	{
		//puck = the last puck in the list
		puck = mFreePucks.at(mFreePucks.size() - 1);
		mUsedPucks.push_back(puck);
		mFreePucks.pop_back();
	}


	return puck;
}



std::vector<Puck *> & PuckManager::getUsedPucks() {
	return mUsedPucks;
}


PuckManager * PuckManager::instance(Ogre::SceneManager * sceneMgr, int pucks ) {
	if (mInstance == 0)  {  
		mInstance = new PuckManager( sceneMgr, pucks );
	}
    return mInstance;
}

Puck * PuckManager::getPuckByName( Ogre::String const & puckName ) const {

	std::vector<Puck *>::const_iterator curr = mUsedPucks.begin();
	std::vector<Puck *>::const_iterator end = mUsedPucks.end();

	for ( ; curr != end ; ++curr ) {
		if ( (*curr)->getName().compare( puckName ) == 0 )  {
			return *curr;
		}
	}

	// curr == end, i.e. no matching puck, so return null.
	return 0;	
}

bool PuckManager::allPucksStopped() const {

	std::vector<Puck *>::const_iterator curr = mUsedPucks.begin();
	std::vector<Puck *>::const_iterator end = mUsedPucks.end();

	//for every puck
	for ( ; curr != end ; ++curr ) {

		//if the velocity is greater than zero
		if ((*curr)->getVelocity() > 0)  {
			return false;
		}//end if
	}//end for

	//if we havn't return true yet, then all the pucks are stopped
	return true;
}