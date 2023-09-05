


// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "composite1.h"
#include "utility.h"
#include "camera.h"


// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------
	
composite1::composite1()
{
	 
		//neck, chest,, waist , armUpL,armUpR,armDownL,armDownR,head
	    //legUpL,legUpR,legDownL,legDownR,footL,footR,handR,handL , shoulderR,shoulderL;
	
	setName("Dancing doll");
	
	//main core it layes inside her  
   // so heart sounded like a good name 
     heart = new sphere(100);
     heart->setPosition(0,0,0);
     heart->setDeformation(0.1,0.1,0.1);
	 heart->setParent(this);
	  
	 //waist
	 waist = new sphere(100);
	 waist->setColour(0.9,0.5,0.6);
	 waist->setPosition(0,0,0);
	 waist->setDeformation(0.5,1,0.5);
	 waist->setParent(heart);
     
	 //chest
	 chest= new sphere(100);
	 chest->setColour(0.9,0.5,0.6);
	 chest->setDeformation(0.8,0.6,0.5);
	 chest->setPosition(0,0.5,0.2);
     chest->setParent(waist);
	 
	 //neck
	 neck= new sphere(100);
	 neck->setColour(1,1,1);
	 neck->setDeformation(0.3,0.5,0.3);
	 neck->setPosition(0,1.35,0);
     neck->setParent(waist);

	 //head
	 tex = new texture("face1.jpg", kContinuousTone, kMipmaps);
	 head= new tsphere(400);
	 head->setDeformation(0.6,0.7,0.6);
	 head->setPosition(0,0.7,0.1);
	 head->setTexture(tex);
     head->setParent(neck);

	 //top hair 
	 hairt= new sweep("hair.txt",100);
	 hairt->setColour(1,0,0);
	 hairt->setDeformation(0.35,0.1,0.3);
	 hairt->setRotation('x',180);
	 hairt->setPosition(0,0.75,0);
     hairt->setParent(head);
	 
	 //hair right side
	 hairr= new sweep("hair.txt",100);
	 hairr->setColour(0,0,0);
	 hairr->setDeformation(0.2,0.05,0.3);
	 hairr->setRotation('x',90,'y',-90);
	 hairr->setPosition(0.7,0,0);
     hairr->setParent(head);

	 //hair left side
	 hairl= new sweep("hair.txt",100);
	 hairl->setColour(0,0,0);
	 hairl->setDeformation(0.2,0.05,0.3);
	 hairl->setRotation('x',90,'y',90);
	 hairl->setPosition(-0.7,0,0);
     hairl->setParent(head);

	 //bun to cover the back of her head  
	 bun1= new sphere( 100);
	 bun1->setColour(0,0,0);
	 bun1->setDeformation(0.6,0.6,0.3);
	 bun1->setPosition(0,0.1,-0.4);
     bun1->setParent(head);

	 //the top bun  
	 bun2= new sphere( 100);
	 bun2->setColour(0,0,0);
	 bun2->setDeformation(0.7,0.6,0.6);
	 bun2->setPosition(0,0.5,-0.5);
     bun2->setParent(head);

	 //hair tie for the top
	 htie= new torus( 100,16,0.5,0.2);
	 htie->setColour(0.9,0.5,0.6);
	 htie->setRotation('x',-45);
	 htie->setPosition(0,-0.2,0.15);
     htie->setParent(bun2);



	//flower 1 for the hair
    f1 = new extrusion("flower.txt","path2.txt");
	f1->setColour(0.9,0.5,0.6);
	f1->setScale(0.5);
	f1->setParent(head);
	f1->setRotation('y', 90,'z',45,'x',30);
	f1->setPosition( 0.56,0.6,0);
	
	//flower2 for the hair
	f2 = new extrusion("flower.txt","path2.txt");
	f2->setColour(0.9,0.5,0.6);
	f2->setScale(0.5);
	f2->setParent(head);
	f2->setRotation('y',-90,'z',-45,'x',30);
	f2->setPosition( -0.56,0.6,0);

	//flower3 for the hair
	f3 = new extrusion("flower.txt","path2.txt");
	f3->setColour(0.9,0.5,0.6);
	f3->setScale(0.5);
	f3->setParent(head);
	f3->setRotation('x',-59);
	f3->setPosition( 0,0.88,0);

	//right shoulder
	shoulderR = new sphere(100);
	shoulderR->setColour(5,5,5);
	shoulderR ->setDeformation(0.7,0.5,0.5);
	shoulderR->setPosition(0.4,0.7,-0.05);
    shoulderR->setParent(waist);

	//left shoulder
	shoulderL = new sphere(200);
	shoulderL->setColour(5,5,5);
	shoulderL->setDeformation(0.7,0.5,0.5);
	shoulderL->setPosition(-0.4,0.7,-0.05);
    shoulderL->setParent(waist);

	//right shoulder joint
	sjr = new sphere(100);
	sjr->setColour(0.9,0.5,0.6);
	sjr->setDeformation(0.4,0.4,0.4);
    sjr->setParent(shoulderR);
	sjr->setPosition(0.6,0,0);
	
    //left shoulder joint   
    sjl = new sphere(100);
	sjl->setColour(0.9,0.5,0.6);
	sjl->setDeformation(0.4,0.4,0.4);
	sjl->setPosition(-0.6,0,0);
    sjl->setParent(shoulderL);

	//upper part of the right arm
	armUpR = new sphere(100);
	armUpR->setColour(1,1,1);
	armUpR->setDeformation(0.3,0.9,0.3);
	armUpR->setParent(sjr);
	armUpR->setPosition(0,-0.7,0);

	//upper part of left arm
	armUpL = new sphere(100);
	armUpL->setColour(1,1,1);
	armUpL->setDeformation(0.3,0.9,0.3);
	armUpL->setParent(sjl);
	armUpL->setPosition(0,-0.7,0);

    //left arm joint == left elbow 
	ajl = new sphere(100);
	ajl->setColour(1,1,1);
	ajl->setDeformation(0.25,0.25,0.25);
	ajl->setParent(armUpL);
	ajl->setPosition(0,-0.7,0);

	//right arm joint == right elbow 
	ajr = new sphere(100);
	ajr->setColour(1,1,1);
	ajr->setDeformation(0.25,0.25,0.25);
	ajr->setParent(armUpR);
	ajr->setPosition(0,-0.7,0);
	  
	//Down part of left arm
	armDownL = new sphere(100);
	armDownL->setColour(1,1,1);
	armDownL->setDeformation(0.27,0.8,0.27);
	armDownL->setParent(ajl);
	armDownL->setPosition(0,-0.8,0);

    //Down part of right arm 
	armDownR = new sphere(100);
	armDownR->setColour(1,1,1);
	armDownR->setDeformation(0.27,0.8,0.27);
	armDownR->setParent(ajr);
	armDownR->setPosition(0,-0.8,0);
	
	//left wrist
	hjl = new sphere(100);
	hjl->setColour(1,1,1);
	hjl->setDeformation(0.2,0.2,0.2);
	hjl->setParent(armDownL);
	hjl->setPosition(0,-0.8,0);

	//right wrist
	hjr = new sphere(100);
	hjr->setColour(1,1,1);
	hjr->setDeformation(0.2,0.2,0.2);
	hjr->setParent(armDownR);
    hjr->setPosition(0,-0.8,0);

	//left hand
	handL = new sphere(100);
	handL->setColour(1,1,1);
	handL->setDeformation(0.2,0.5,0.3);
	handL->setParent(hjl);
	handL->setPosition(0,-0.4,0);
	
	//right hand
    handR = new sphere(100);
	handR->setColour(1,1,1);
	handR->setDeformation(0.2,0.5,0.3);
	handR->setParent(hjr);
	handR->setPosition(0,-0.4,0);

	//hip
	hip = new sphere(100);
	hip->setColour(0.9,0.5,0.6);
	hip->setDeformation(0.9,0.6,0.6);
	hip->setPosition(0,-1,0);
    hip->setParent(heart);
   
    //skirt
    skirt =new sweep("skirt.txt",200);
    skirt->setColour(4,4,1,0.6);
    skirt->useSmoothShading();
    skirt->setDeformation(1.95,0.9,1.8);
    skirt->setRotation('x',180);
    skirt->setPosition(0,0.61,0);
    skirt->setParent(hip);

	
    //left leg joint  (hip-leg)
	ljl = new sphere(100);
	ljl->setColour(1,1,1);
	ljl ->setDeformation(0.49, 0.49 ,0.49);
	ljl->setPosition(-0.55,-0.1,0);
    ljl->setParent(hip);

	//right leg joint  (hip-leg)
	 ljr = new sphere(100);
	 ljr->setColour(1,1,1);
	 ljr ->setDeformation(0.49, 0.49 ,0.49);
	 ljr->setPosition(0.55,-0.1,0);
     ljr->setParent(hip);

	 //left leg upper part
     legUpL = new sphere(100);
	 legUpL->setColour(1,1,1);
	 legUpL->setDeformation(0.49, 1.3 ,0.49);
	 legUpL->setPosition(0,-1.3,0.2);
     legUpL->setParent(ljl);

	 //right leg upper part
	 legUpR = new sphere(100);
	 legUpR->setColour(1,1,1);
	 legUpR->setDeformation(0.49, 1.3 ,0.49);
	 legUpR->setPosition(0,-1.3,0.2); 
	 legUpR->setParent(ljr);

	 //right knee
	 nr = new sphere(100);
	 nr->setColour(1,1,1);
	 nr->setDeformation(0.35, 0.35 ,0.35);
	 nr->setPosition(0,-1.2,0); 
	 nr->setParent(legUpR);

	 //left knee
	 nl = new sphere(100);
	 nl->setColour(1,1,1);
	 nl->setDeformation(0.35, 0.35 ,0.35);
	 nl->setPosition(0,-1.2,0); 
     nl->setParent(legUpL);

	 //down part of left leg
     legDownL = new sphere(100);
	 legDownL->setColour(1,1,1);
	 legDownL->setDeformation(0.4, 1.3 ,0.43);
	 legDownL->setPosition(0,-1,-0.1);
     legDownL->setParent(nl);

	 //Down part of leg right
	 legDownR = new sphere(100);
	 legDownR->setColour(1,1,1);
	 legDownR->setDeformation(0.4, 1.3 ,0.43);
	 legDownR->setPosition(0,-1,-0.1);
     legDownR->setParent(nr);

	 //right foot joint
	 fjr = new sphere(100);
	 fjr->setColour(0.9,0.5,0.6);
	 fjr->setDeformation(0.25, 0.25 ,0.25);
     fjr->setPosition(0,-1.3,0);
     fjr->setParent(legDownR);
	 
	 //left foot joint
	 fjl = new sphere(100);
	 fjl->setColour(0.9,0.5,0.6);
	 fjl->setDeformation(0.25, 0.25 ,0.25);
	 fjl->setPosition(0,-1.3,0);
     fjl->setParent(legDownL);

	 //right foot
	 footR = new sphere(100);
	 footR ->setColour(1,0,0);
	 footR->setDeformation( 0.3, 0.25 ,0.6);
	 footR->setPosition(0,-0.1,0.3);
     footR->setParent(fjr);

	 //left foot
	 footL= new sphere(100);
	 footL ->setColour(1,0,0);
	 footL->setDeformation( 0.3, 0.25 ,0.6);
	 footL->setPosition(0,-0.1,0.3);
     footL->setParent(fjl);

	 //two slices sk1 sk2 
	 //to make each foot look like skating shoe
	 sk1= new cube();
	 sk1 ->setColour(0.65,0.8,0.85);
	 sk1->setDeformation(0.05,0.25,0.53);
	 sk1->setPosition(0,-0.3,-0.04);
     sk1->setParent(footL);

	 sk2= new cube();
	 sk2 ->setColour(0.65,0.8,0.85);
	 sk2->setDeformation(0.05,0.25,0.53);
	 sk2->setPosition(0,-0.3,-0.04);
     sk2->setParent(footR);


	gShapeVector.push_back(this);
	
}

void composite1::hide()
{
	head->hide();  
	neck->hide();  
	chest->hide(); 
	heart->hide();  
	hip->hide();  
	armUpL->hide(); 
	armUpR->hide(); 
	armDownL->hide(); 
	armDownR->hide(); 
	legUpL->hide(); 
    legUpR->hide(); 
	legDownL->hide(); 
	legDownR->hide(); 
	footL->hide(); 
	footR->hide(); 
	handR->hide();  
	handL->hide();  
	shoulderR->hide();  
	shoulderL->hide(); 
	ajl->hide();  
	ajr->hide(); 
	ljl->hide();  
	ljr->hide(); 
	nl->hide();  
	nr->hide();  
	fjr->hide();  
	fjl->hide();  
	hjr->hide();  
	hjl->hide();   
	sjr->hide();  
	sjl->hide();   
	waist->hide();  
    hairt->hide();  
	hairl->hide(); 
	hairr->hide();  
	skirt->hide();  
    bun1->hide();   
	bun2->hide(); 
    f1->hide();  
	f2->hide();  
	f3->hide(); 
    htie->hide(); 
    sk1->hide();  
	sk2->hide(); 

};
	
void composite1::show()
{

	head->show();  
	neck->show(); 
	chest->show(); 
	heart->show();
	hip->show();  
	armUpL->show(); 
	armUpR->show(); 
	armDownL->show(); 
	armDownR->show(); 
	legUpL->show(); 
    legUpR->show(); 
	legDownL->show(); 
	legDownR->show(); 
	footL->show(); 
	footR->show(); 
	handR->show();  
	handL->show();  
	shoulderR->show();  
	shoulderL->show(); 
	ajl->show();  
	ajr->show(); 
	ljl->show();  
	ljr->show(); 
	nl->show();  
	nr->show();  
	fjr->show();  
	fjl->show();  
	hjr->show();  
	hjl->show();   
	sjr->show();  
	sjl->show();   
	waist->show();  
    hairt->show();  
	hairl->show();  
	hairr->show();  
	skirt->show();  
    bun1->show();   
	bun2->show(); 

    f1->show();  
	f2->show();  
	f3->show(); 
    htie->show(); 
    sk1->show();  
	sk2->show(); 

}

void composite1 ::animate(float time)
{
	
	float x1,z1,xw;
	
	if(time<=10)
	{
       x1=time*15;
	   z1=time*15;
	   xw=time*15;
     
	
	  if(0<time && time<=4.5)
	  {
     ljr->setRotation('x',x1);
     sjr->setRotation('z',z1,'x',x1);
	 sjl->setRotation('z',-z1,'x',x1);
	  }

	 float z=speedUp(0,10,-50,0); 
     heart->setPosition(0,0,z);
	
   }
     
	
	
	

		else if(10<time && time<=20)
       {
		   if( time<17 )
	        {  
             ljr->setRotation('x',-x1/100);
	         sjr->setRotation( 'x',-x1/200);
	         sjl->setRotation('x',-x1/200);
           }

		
			float p1 = 0;
          float p2 = +180;
         float duration = 0.4; 
		 
		 hjl->setRotation('z', -50);
		 hjr->setRotation('z',-30);
		 sjr->setRotation('x',-180);
		 sjl->setRotation('x',90,'y',200);
		 
		 nl->setRotation('x',90);
	
		float angle = (((p2 - p1) / duration) * time) + p2;
         heart->setRotation('y', angle);
		 
		
		}
	
	else if(20<time && time<=20.5)
	
		{
		
		sjr->setRotation('x',0);
		 sjl->setRotation('x',0);
		 nl->setRotation('x',0);
	     
		  hjl->setRotation('z', 0);
		 hjr->setRotation('z',0);
		
		}



else if(20.5<time && time<=26)
	{
       x1=time*3;
	   z1=time*3;
	   xw=time*5;
     
	 if( 22 >=time && 20.5<time )
	 {
     ljr->setRotation('x',x1);
     sjr->setRotation('z',z1,'x',x1);
	 sjl->setRotation('z',-z1,'x',x1);
	
	 }
	
	  
	 float z=speedUp(21,4,0,-40); 
     heart->setPosition(0,0,z);

	}


	
	else if(26<time && time<=36)
    {
		
			float p1 = -180;
          float p2 = +180;
         float duration = 0.5; 
		 
		 if(time<28)
		 {
		 hjl->setRotation('z', 15);
		 hjr->setRotation('z',-15);
		 sjr->setRotation('z',-10,'x',-180);
		 sjl->setRotation('z',10,'x',-180);
		 
		 nr->setRotation('x',60);
		 ljr->setRotation('x',-60,'z',-40);
		 }

		 else if(time<28.1)
		 {
		 hjl->setRotation('z',0);
		 hjr->setRotation('z',0);
		 sjr->setRotation('z',0,'x',0);
		 sjl->setRotation('z',0,'x',0);
		 
		 nr->setRotation('x',0);
		 ljr->setRotation('x',0,'z',0);
		 }

		 else if(time<30)
		 {
		 
		 sjr->setRotation('z',90);
		 sjl->setRotation('z',-90);
		 
		 nr->setRotation('x',0);
		 ljl->setRotation('z',-30);
		 }
	
		 float angle = (((p2 - p1) / duration) * time) + p1;
         heart->setRotation('y', angle);
		  
		 float z=speedUp(30,4,-40,-10); 
         heart->setPosition(0,0,z);
		 
		
		}

	


	


}



