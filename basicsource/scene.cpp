// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// scene.cpp



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "constants.h"			// system-wide constants
#include "utility.h"			// general utility functions
#include "light.h"
#include "camera.h"
#include "texture.h"
#include "scene.h"
#include "snd.h"
#include "skybox.h"
#include "fog.h"
#include "viewfrustum.h"

// #includes for geometry
#include "sweep.h"
#include "extrusion.h"
#include "cube.h"
#include "sphere.h"
#include "torus.h"
#include "terrain.h"
#include "billboard.h"
#include "plane.h"
#include "tsphere.h"
#include "cylinder.h"
#include "disc.h"
#include "tcube.h"

#include "composite1.h"
#include "composite2.h"
// -----------------------------------------------------------------------------------------
// global variables
// -----------------------------------------------------------------------------------------
extern ProgramMode		gProgramMode;							// initially, we're not animating

extern cameraClass		gCamera;								// the camera
extern object3d			*gSky;									// the global skybox
extern fog				*gFog;									// the global fog
extern viewfrustum		*gViewFrustum;							// the global view frustum object
extern float			gCurrentFrameTime;						// the time that the current animation frame was started

extern vector<object3d*> gShapeVector;
typedef vector<object3d*>::iterator shapeVectorIterator;






// -----------------------------------------------------------------------------------------
// variables that represent 3D objects being used in the animation
// -----------------------------------------------------------------------------------------
// these are really global variables, but you shouldn't need to access them from anywere
// except in this file 
// -----------------------------------------------------------------------------------------

// pointer of shapes defined here

composite1 *f;
composite2 *f1;
terrain *theGround;
tcube *d;
texture *tex ;

// some lights
light *ambient, *light0, *light1, *light2;



// -----------------------------------------------------------------------------------------
// constructScene
// -----------------------------------------------------------------------------------------
// This function constructs the objects required for the animation.  It is only called once
// when the program is first run.
// Use this to create child objects and bind them to their parents.
// -----------------------------------------------------------------------------------------

void constructScene()
{    
	// create the lights first
	ambient = new light(GL_LIGHT_MODEL_AMBIENT);
	light0 = new light(GL_LIGHT0);
	light1 = new light(GL_LIGHT1);
    light2 = new light(GL_LIGHT2);
	///Add 3D objects here
	
	gSky = new skybox("sky16-");

	 f = new composite1;
     f1 = new composite2;
	

	   tex = new texture("122.jpg", kContinuousTone, kMipmaps);
	   d= new tcube(); 
	   d->setDeformation(100,1,100);
	
	   d->setTexture(tex);
       d->setPosition(0,-8,0);
	 
	 theGround = new terrain("ground.bmp");
	 theGround ->setPosition(0, -9, 0);
	 theGround ->setScale(2);
	 theGround->useSmoothShading();
	 theGround->setColour(2,1,1);

}




// -----------------------------------------------------------------------------------------
// resetScene
// -----------------------------------------------------------------------------------------
// This function is called whenever the animation is restarted.  Use it to reset objects
// to their starting position or size, or to reset any aspects of the objects that
// might have been altered during an animation sequence.
// -----------------------------------------------------------------------------------------

void resetScene()
{
	// initialise the camera
	gCamera.setPosition(0, 1, 10);
	gCamera.setTarget(f);
	
	
	
	
	ambient->setColour(0.5, 0.5, 0.5, 1.0);
    
	light0->turnOn();
	light0->setPosition(-10, 10, 5);
	light0->setColour(0.7, 0.7, 0.7, 1.0);
	light0->setSpecularColour(0.7, 0.7, 0.7, 1.0);
	light0->makePositional();
	light0->setLinearAttenuation(0.1);
	
	light1->turnOn();
	light1->setPosition(10, 10, -5);
	light1->setColour(0.7, 0.7, 0.7, 1.0);
	light1->setSpecularColour(0.7, 0.7, 0.7, 1.0);
	light1->makePositional();
	light1->setLinearAttenuation(0.1);

	light2->turnOn();
	light2->setPosition( 10, 10,-250);
	light2->setColour(0.7, 0.7, 0.7, 1.0);
	light2->setSpecularColour(0.7, 0.7, 0.7, 1.0);
	light2->makePositional();
	light2->setLinearAttenuation(0.1);
    
	// reset all objects to their starting position
	 f->setPosition(0,0,-8);
	 f1->setPosition(5,0,-8);

}




// -----------------------------------------------------------------------------------------
// animateForNextFrame
// -----------------------------------------------------------------------------------------
// This function is called to animate objects ready for the next frame
// -----------------------------------------------------------------------------------------

void animateForNextFrame(float time, long frame)
{

	////Animate 3D objects here
	
	 gCamera.setTarget(f);
	
	 if(21<time && time<=31)
	{  
		gCamera.setPosition( 0,0,-70);
		gCamera.setTarget(2,0,0);

	}
	 
	 f->animate(time);
	 f1->animate(time);
	 


	 //eventually stop
	 if (time >= 60)
	   gProgramMode = kpmFinished;

}


