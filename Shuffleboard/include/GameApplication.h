#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H

#include <OIS/OIS.h>

#include "BaseApplication.h"
#include "GameConstants.h"
#include "Shuffleboard.h"
#include "PuckManager.h"
#include <vector>
#include "Gui3D.h"
#include "Gui3DPanel.h"
#include "MyPurplePanelColors.h"

class GameApplication : public BaseApplication {
public:
	GameApplication();
	virtual ~GameApplication();

protected:
	virtual void createScene();
	virtual void destroyScene();
	virtual void createCamera();
	bool frameRenderingQueued(const Ogre::FrameEvent& evt);
	
	// OIS::KeyListener
	bool keyPressed( const OIS::KeyEvent& evt );
	bool keyReleased( const OIS::KeyEvent& evt );

	// OIS::MouseListener
	bool mouseMoved( const OIS::MouseEvent& evt );
	bool mousePressed( const OIS::MouseEvent& evt, OIS::MouseButtonID id );
	bool mouseReleased( const OIS::MouseEvent& evt, OIS::MouseButtonID id );

	void createGamePanel();


private:	
	bool mShutDown;
	bool mFreeLookCam;
	void resetCamera();
	Puck * mPuck;
	Ogre::Real mElapsedTime;
	Ogre::Real mCurrentTime;

	// Gui3D main object
	Gui3D::Gui3D* mGui3D;

	// The main panel (display in 3D)
	Gui3D::Panel* mPanel;
	Gui3D::ProgressBar* mForceProgressBar;
	MyPurplePanelColors mMyPurplePanelColors;

	bool mGetInputForce;

};

#endif