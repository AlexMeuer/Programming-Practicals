#ifndef PUCKMANAGER_H
#define PUCKMANAGER_H

#include "Puck.h"
#include <vector>

using namespace std;

class PuckManager {
public:
	
	void update( Ogre::Real const & timeSinceLastFrame );
	
	Puck * getNextPuck();	

	std::vector<Puck *> & getUsedPucks();
	
	static PuckManager * instance(Ogre::SceneManager * sceneMgr = 0, int pucks = GameConstants::sNUMBER_PUCKS );

	Puck * getPuckByName( Ogre::String const & puckName ) const;

	bool allPucksStopped() const;
	

protected:
	PuckManager( Ogre::SceneManager *sceneMan, int pucks );
	void createPucks(int pucks);

	// Member variables...

	Ogre::SceneManager *mSceneMgr;				// The overall scene manager.
	std::vector<Puck *> mFreePucks;				// A container for all the available pucks.
	std::vector<Puck *> mUsedPucks;				// A container for all the pucks currently in use.
	int mPucks;									// Total number of pucks.

	static PuckManager * mInstance;
};
#endif

