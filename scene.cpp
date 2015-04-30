#include "scene.h"
#include <iostream>
#include <cstdint>
using namespace std;
using std::uint8_t;

Scene::Scene	(	int 	max	)
{

  INDEX = new Image*[max];

  for (int i=0;i<max;i++)
  {INDEX[i]=NULL;}

  this->Max = max;

  X=new int[max];
  Y=new int[max];
}

Scene::Scene	(	const Scene & 	source	)
{
  copy(source);
}


const Scene & Scene::operator=	(	const Scene & 	source	)
{

  if (this != &source)
{
 clear();
 copy(source);
}

return *this;
}



void Scene::changemaxlayers	(	int 	newmax	)
{

//check if invalid
//cout<<Max<<endl;
  for (int i=0;i < Max;i++)
  {
    //cout<<"2"<<endl;

    if( (INDEX[i]!= NULL) & (i > (newmax-1) ) )
    {
      cout << "invalid newmax" << endl;
      return;
    }
  }
//passed


//change [] length
  Image **oldINDEX=INDEX;
  INDEX = new Image*[newmax];

  for (int i=0;i < newmax;i++)
  {
    INDEX[i]=NULL;
  }
  //passed

if (oldINDEX != NULL)
{
  for (int i=0;i < Max;i++)
  {
    if (oldINDEX[i]!= NULL)
      {
        INDEX[i]= new Image;
        *(INDEX[i])=*(oldINDEX[i]);
        delete oldINDEX[i];
        oldINDEX[i]=NULL;
        //cout<<"2"<<endl;
      }
  }

//FIXMEed

  delete [] oldINDEX;
  oldINDEX=NULL;
}


//  cout<< Max<<endl;




Max = newmax;
  return;
}






void Scene::addpicture	(	const char * 	FileName,
  int index,int x,int y )
{

  string filename(FileName);

  //Image *p=new Image;
  //p->readFromFile(filename);
  Image p;
  p.readFromFile(filename);



  if (0 > index | index >= Max)
  {
    cout << "index out of bounds" << endl;
    return;
  }

  if(INDEX[index]!=NULL)
  {
    delete INDEX[index];
    *INDEX[index]=p;
  }
  else{

//INDEX[index]==NULL
//delete INDEX[index];
  INDEX[index]= new Image();
  *INDEX[index]=p;
  }



  X[index]=x;
  Y[index]=y;


}




void Scene::changelayer	(	int 	index,
int 	oldINDEX )
{
    if(index==oldINDEX){return;}




    if (0 > index | index >= Max |0 > oldINDEX | oldINDEX >= Max )
    {
      cout << "invalid index" << endl;
      return;
    }

    if(INDEX[oldINDEX]!=NULL)
    {
      delete INDEX[oldINDEX];
      INDEX[oldINDEX]=NULL;
      INDEX[oldINDEX]=INDEX[index];
      INDEX[index]=NULL;

      X[oldINDEX]=X[index];
      Y[oldINDEX]=Y[index];
      X[index]=0;
      Y[index]=0;
      return;
    }

    else
  {
    INDEX[oldINDEX]=INDEX[index];
    INDEX[index]=NULL;
    X[oldINDEX]=X[index];
    Y[oldINDEX]=Y[index];
    X[index]=0;
    Y[index]=0;
    return;
  }
}


void Scene::translate	(	int index,
int xcoord,int ycoord )
{

  if (0 > index | index >= Max | INDEX[index]==NULL )
  {
    cout << "invalid index" << endl;
    return;
  }

  X[index]=xcoord;
  Y[index]=ycoord;
}



void Scene::deletepicture	(	int 	index	)
{
  if (0 > index | index >= Max | INDEX[index]==NULL )
  {
    cout << "invalid index" << endl;
    return;
  }

  delete INDEX[index];

  INDEX[index]=NULL;

}



Image * Scene::getpicture	(	int 	index	)	const
{
  if (0 > index | index >= Max | INDEX[index]==NULL )
  {
    cout << "invalid index" << endl;
    return NULL;
  }

  return INDEX[index];



}




Image Scene::drawscene	(		)	const
{

  size_t minWid=0;
  size_t minHig=0;

/*
  size_t *Wid;
  Wid=new size_t[Max]();
  size_t *Hig;
  Hig=new size_t[Max]();

  for (int i=0;i < Max;i++)
  {
    if(INDEX[i]!=NULL)
    {

  Wid[i]=X[i]+(*INDEX[i]).width();

  Hig[i]=Y[i]+(*INDEX[i]).height();
    }
  }

  */
//  minWid=Wid[0];
//  minHig=Hig[0];

  for (int i=0;i < Max;i++)
{
  if(INDEX[i]!=NULL)
  {

   if(minWid<X[i]+(*INDEX[i]).width())
  {minWid=X[i]+(*INDEX[i]).width();}
//  else
//{minWid=Wid[i];}

  if(minHig<Y[i]+(*INDEX[i]).height())
  {minHig=Y[i]+(*INDEX[i]).height();}
//  else
//{minHig=Hig[i];}
  }

}

/*
delete []Wid;
delete []Hig;
Wid=NULL;
Hig=NULL;
*/

Image *output;
output=new Image;

output->resize(minWid, minHig);



for (int i=0;i < Max;i++)
{

  if(INDEX[i]!=NULL)
  {

for(size_t xi=0;xi<(*INDEX[i]).width();xi++)
{
  for(size_t yi=0;yi<(*INDEX[i]).height();yi++)
  {

    RGBAPixel *pOld = (*INDEX[i])(xi, yi);
    RGBAPixel *pNew = (*output)(xi+X[i],yi+Y[i]);

      pNew->red  = pOld->red;
      pNew->green  = pOld->green;
      pNew->blue  = pOld->blue;



  }
}
  }

}

Image final = *output;
delete output;
output = NULL;

return final;



}






//helper functions

void Scene::copy( const Scene & other )
{

//if (INDEX != NULL)
//{  clear();}

  //Image **alpha;
  INDEX = new Image*[other.Max]();
  X=new int[other.Max]();
  Y=new int[other.Max]();
  Max = other.Max;
//  *X=*other.X;
//  *Y=*other.Y;

//for (int i=0;i<other.Max;i++)
//{
//  INDEX[i]=NULL;
//}



  for (int i=0;i<Max;i++)
  {
    X[i]=other.X[i];
    Y[i]=other.Y[i];
    INDEX[i]=new Image;



    if(other.INDEX[i]!=NULL)
  {

    //INDEX[i]=new Image;
    *(INDEX[i])=*(other.INDEX[i]);

  }
  else
    {
      delete  INDEX[i];
      INDEX[i]=NULL;
    }

  }


}


void Scene::clear()
{
  if (INDEX != NULL)
  {
    for (int i=0;i<Max;i++)
    {
      if(INDEX[i] != NULL)
      {
        //not NULL but points to garbage
        delete INDEX[i];
        INDEX[i]=NULL;
      }
    }
    delete [] INDEX;
    INDEX=NULL;
    delete [] X;
    X=NULL;
    delete [] Y;
    Y=NULL;
  }

}

//deconstructor



Scene::~Scene ()
{

clear();

}
