// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2021
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: HXP
//
// composite1.h
//
// This file declares the class for composite1 objects, based on the
// generic 3D object


#ifndef _composite1_H
#define _composite1_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include "sphere.h"
#include "cube.h"
#include "sweep.h"
#include "extrusion.h"
#include "disc.h"
#include "torus.h"
#include "tsphere.h"
#include "texture.h"


// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class composite1 : public object3d
{
public:
						composite1();
		virtual void	hide(void);
		virtual void	show(void);

		
		void animate(float time);

private:


sphere *neck ,*chest,*heart, *hip , *armUpL,*armUpR,*armDownL,*armDownR,
	    *legUpL,*legUpR,*legDownL,*legDownR,*footL,*footR,*handR,*handL , *shoulderR,*shoulderL,
		
		*ajl , *ajr,*ljl ,*ljr,* nl,*nr,*fjr,*fjl,*hjr,*hjl ,*sjr,*sjl, *waist ;

tsphere *head ;
texture *tex ;

sweep *hairt , *hairl, *hairr ,*skirt ;
sphere *bun1 ,*bun2;

extrusion *f1 ,*f2,*f3;
torus *htie;

cube *sk1 ,*sk2;

};


#endif // _composite1_H

