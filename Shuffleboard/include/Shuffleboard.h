#ifndef SHUFFLEBOARD_H
#define SHUFFLEBOARD_H

#include <Ogre.h>
#include <OIS/OIS.h>
#include "GameConstants.h"
#include "PuckManager.h" 

using namespace Ogre;

class Shuffleboard {
public:	
	
	static Shuffleboard * instance(SceneManager * sceneMgr = 0 );

	void initialise();	

	void setArrowVisible(bool visible);

	void rotateArrow(OIS::MouseEvent const & e);

	void launchPuck();

	bool getInputForce();

	void resetArrowOrientation();

	Ogre::Real getPuckForce() const;

protected:
	Shuffleboard( SceneManager *sceneMan );

	SceneManager *mSceneMgr;		// The overall scene manager.
	
	static Shuffleboard * mInstance;

	Ogre::SceneNode *mArrow;

	// The input force to apply to the puck.
	Ogre::Real mForce;

};



#endif

