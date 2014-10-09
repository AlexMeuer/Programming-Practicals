#include "GameApplication.h"

using namespace Ogre;


//-------------------------------------------------------------------------------------
GameApplication::GameApplication() :     	
	mShutDown( false ),mFreeLookCam(false), mGetInputForce(false)
{
}

//-------------------------------------------------------------------------------------
GameApplication::~GameApplication() {
	
}

//-------------------------------------------------------------------------------------
void GameApplication::createCamera() {
	// Create the camera here...
	mCamera = mSceneMgr->createCamera("BoardCamera");
	mCamera->setNearClipDistance(1);
	mCamera->setPosition(Vector3(5,12,21));
	mCamera->pitch(Ogre::Degree(-35));

	//create a default camera controller
	mCameraMan = new OgreBites::SdkCameraMan(mCamera);
	Ogre::Real speed = mCameraMan->getTopSpeed();
	mCameraMan->setTopSpeed(speed/4);

}

//-------------------------------------------------------------------------------------   
void GameApplication::createScene() {
	// Create your scene here...	

	//set ambient light
	Ogre::Light* light = mSceneMgr->createLight("MainLight");
	light->setPosition(15,15,3);

	//create the puckManager singleton
	PuckManager::instance(mSceneMgr, 10);

	//create the shuffleboard singleton
	Shuffleboard::instance(mSceneMgr);

	//mPuck = PuckManager::instance()->getNextPuck();

	/*	we should only create a puck when SPACE key is pressed
	//This gives us the correct x,y,z position for the puck launch at the top of the shuffleboard
	Ogre::Real centreX = ( GameConstants::MAX_X - GameConstants::MIN_X ) / 2 + GameConstants::MIN_X; 
 	Ogre::Vector3 launchPos( centreX, GameConstants::LAUNCH_Y, GameConstants::LAUNCH_Z );
	
	mPuck->activate(launchPos);
	mPuck->applyForce(Ogre::Real(7));*/

	mGui3D = new Gui3D::Gui3D(&mMyPurplePanelColors);
	Ogre::Viewport *viewport = mWindow->getViewport(0);
	mGui3D->createScreen(viewport, "purple", "mainScreen");
	createGamePanel();

	mCurrentTime = 0;
}


//-------------------------------------------------------------------------------------   
void GameApplication::destroyScene() {

}

// KeyListener
bool GameApplication::keyPressed(const OIS::KeyEvent &e) {		
	switch (e.key) {
	case OIS::KC_ESCAPE: 
		mShutDown = true;
		break;
	case OIS::KC_T:
		if(mFreeLookCam)
		{
			mFreeLookCam = false;
			resetCamera();
		}
		else
		{
			mFreeLookCam = true;
		}
		break;

	case OIS::KC_P:
		/*mPuck->applyForce(Ogre::Real(6));*/
		break;
	case OIS::KC_L:
		/*mPuck->applyForce(Ogre::Real(8));*/
		break;

		//when space is pressed, try launch a new puck
	case OIS::KC_SPACE:
		//mPuck = PuckManager::instance()->getNextPuck();
		//
		////This gives us the correct x,y,z position for the puck launch at the top of the shuffleboard
		//Ogre::Real centreX = ( GameConstants::MAX_X - GameConstants::MIN_X ) / 2 + GameConstants::MIN_X; 
		//Ogre::Vector3 launchPos( centreX, GameConstants::LAUNCH_Y, GameConstants::LAUNCH_Z );

		//mPuck->activate(launchPos);
		/*Shuffleboard::instance()->launchPuck();
		Shuffleboard::instance()->setArrowVisible(false);*/
        if ( PuckManager::instance()->allPucksStopped() )
		{
			Shuffleboard::instance()->setArrowVisible( false );
			mGetInputForce = true;
		} 
		break;
	}
	
	mCameraMan->injectKeyDown(e);
	return true;
}

bool GameApplication::keyReleased(const OIS::KeyEvent &e) { 
	mCameraMan->injectKeyUp(e);
	switch (e.key)
	{
		case OIS::KC_SPACE:
			mGetInputForce = false;
			mForceProgressBar->reset();
			if ( PuckManager::instance()->allPucksStopped() )
			{
				Shuffleboard::instance()->launchPuck();
			}
			break;
		default:
			break;
	} 

	return true;
}

bool GameApplication::mouseMoved(const OIS::MouseEvent &e) {					
	Shuffleboard::instance()->rotateArrow(e);
	return true;
}

bool GameApplication::mousePressed( const OIS::MouseEvent& evt, OIS::MouseButtonID id ){
	return true;
}

bool GameApplication::mouseReleased( const OIS::MouseEvent& evt, OIS::MouseButtonID id ){
	return true;
}


//-------------------------------------------------------------------------------------
bool GameApplication::frameRenderingQueued(const Ogre::FrameEvent& evt)
{		
	if (mWindow->isClosed()) { 
		return false;
	}
	if (mShutDown) {
		return false;
	}
	
	mKeyboard->capture();
	mMouse->capture();
	
	mTrayMgr->frameRenderingQueued(evt);

	// For free look camera style..
	mCameraMan->frameRenderingQueued(evt);

	if(!mFreeLookCam)
	{
		mCameraMan->manualStop();
	}

	mElapsedTime = evt.timeSinceLastFrame;
	mCurrentTime += evt.timeSinceLastFrame;

	if ( mGetInputForce ) {
  		mGetInputForce = Shuffleboard::instance()->getInputForce();
		mForceProgressBar->setValue(Shuffleboard::instance()->getPuckForce() / GameConstants::MAX_FORCE );
	} 

	if ( mCurrentTime > GameConstants::UPDATE_GRANULARITY )
	{ 
		mCurrentTime -= GameConstants::UPDATE_GRANULARITY; 
		PuckManager::instance()->update(evt.timeSinceLastFrame);
	} 

	//arrow is visible if all pucks are stopped (just another way of doing the if/else below)
	//Shuffleboard::instance()->setArrowVisible(PuckManager::instance()->allPucksStopped());
	if(PuckManager::instance()->allPucksStopped()) {
		Shuffleboard::instance()->setArrowVisible(true);
		mPanel->mNode->setVisible(true);
	}
	else {
		Shuffleboard::instance()->setArrowVisible(false);
		mPanel->mNode->setVisible(false);
	}
		
	return true;
}

void GameApplication::resetCamera()
{
	mCamera->setPosition(Vector3(5,12,21));
	// mCamera->lookAt( );
}

//--------------------------------------------------------------------------------
void GameApplication::createGamePanel() {
	mPanel = new Gui3D::Panel(mGui3D, mSceneMgr, Ogre::Vector2(400, 100), 10, "purple", "test_panel");
	mPanel->makeCaption(5, -30, 390, 30, "Launch Power");	//caption coordinates are relative to panel
	mPanel->mNode->setPosition(10, GameConstants::LAUNCH_Y + 6, GameConstants::LAUNCH_Z - 7);
	mForceProgressBar = mPanel->makeProgressBar(10, 40, 380, 30);
} 




#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
#include "macUtils.h"
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
	int main(int argc, char *argv[])
#endif
	{
		// Create application object
		GameApplication app;

		try {
			app.go();
		} catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
			MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
			std::cerr << "An exception has occurred: " <<
				e.getFullDescription().c_str() << std::endl;
#endif
		}

		return 0;
	}

#ifdef __cplusplus
}
#endif
