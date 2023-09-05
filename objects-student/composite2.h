// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2021
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: HXP
//
// composite2.h
//
// This file declares the class for composite2 objects, based on the
// generic 3D object


#ifndef _composite2_H
#define _composite2_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include "sphere.h"
#include "cube.h"
#include "sweep.h"
#include "extrusion.h"


// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class composite2 : public object3d
{
public:
						composite2();
		virtual void	hide(void);
		virtual void	show(void);
		
		void animate(float time);

private:
sweep *dress;
extrusion *w1 , *w2,*f1 ,*f2;
sphere *head , *hl, *hr, *lr, *ll , *dl,*dr;

};


#endif // _composite2_H

