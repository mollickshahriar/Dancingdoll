


// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "composite2.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------
	
composite2::composite2()
{
	
	setName("composite2");
	 dress= new sweep("dress.txt",200);
	 dress->setColour(1,0,0);
	 dress->setPosition(0,0,0);
	 dress->setParent(this);

	 head =new sphere(200); 
	 head->setScale(0.6);
	 head->setPosition(0,2.5,0);
	 head->setColour(1,1,1);
	 head->setParent(dress);

    f1 = new extrusion("flower.txt","path2.txt");
	f1->setScale(1);
	f1->setParent(head);
	f1->setRotation('y', 90,'z',45);
	f1->setPosition( 0.8,0.6,0);
	
	f2 = new extrusion("flower.txt","path2.txt");
	f2->setScale(1);
	f2->setParent(head);
	f2->setRotation('y',-90,'z',-45);
	f2->setPosition( -0.8,0.6,0);

	w1 =new extrusion("wing.txt","path.txt");
	w1->setScale(2);
	w1->setRotation('x',10);
	w1->setPosition(0,1.4,-0.7);
	w1->setParent(dress);


    w2 =new extrusion("wing.txt","path.txt");
	
    w2->setScale(2);
	w2->setOffset(0,0,-0.2);
	w2->setRotation('y',180,'x',10);
    w2->setPosition(0,1.4,-0.7);
	w2->setParent(dress);

	 dr= new sphere(100);
	 dr->setScale(0.4);
     dr->setColour(5,1,1);
	 dr->setPosition(0.6,1.7,0);
     dr->setParent(dress);

	 hr= new sphere(100);
	 hr->setDeformation(0.7,0.15,0.15);
	 hr->setScale(2.5);
	 hr->setRotation('z',-40);
	 hr->setPosition(1,-0.7,0);
	 hr->setColour(1,1,1);
	 hr->setParent(dr);
	
	 
	 dl= new sphere(100);
	 dl->setScale(0.4);
     dl->setColour(5,1,1);
	 dl->setPosition(-0.6,1.7,0);
     dl->setParent(dress);


	 hl= new sphere(100);
	 hl->setDeformation(0.7,0.15,0.15);
	 hl->setScale(2.5);
	 hl->setRotation('z',40);
	 hl->setPosition(-1,-0.7,0);
	 hl->setColour(1,1,1);
	 hl->setParent(dl);
	


	
	 lr= new sphere(100);
	 lr->setDeformation(0.8,0.2,0.2);
	 lr->setPosition(-0.5,0,0);
	 lr->setColour(1,1,1);
	 lr->setRotation('z',-90);
	 lr->setParent(dress);

	
	  ll= new sphere(100);
	  ll->setDeformation(0.8,0.2,0.2);
	  ll->setPosition(0.5,0,0);
	  ll->setColour(1,1,1);
	  ll->setRotation('z',90);
	  ll->setParent(dress);
	
	gShapeVector.push_back(this);
	
}

void composite2::hide()
{
	
	dress->hide();
    w1->hide();  
	w2->hide();
	f1->hide(); 
    f2->hide();
    head->hide();   
	hl->hide();
	hr->hide(); 
	lr->hide(); 
	ll->hide(); 
	dl->hide();
	dr->hide();




}

void composite2::show()
{

	dress->show();
    w1->show();
	w2->show();
	f1->show(); 
    f2->show();
    head->show();   
	hl->show();
	hr->show(); 
	lr->show(); 
	ll->show(); 
	dl->show();
	dr->show();


}

void composite2 ::animate(float time)
{


	float p1 = -5;
    float p2 = +10;
   float duration = 5;
    
   float y = (((p2 - p1) / duration) * time) + p1;
   this->setPosition(0, y, 0);
   
   f1->setRotation('y', 90,'x',time*100,'z',40);
   f2->setRotation('y',-90,'x',time*100,'z',-40);
   
   
   w1->setRotation('y',+30+20*sin_d(time*720));
   w2->setRotation('y', 80+70 -45*sin_d(time*720));  


	}
   
	



  



