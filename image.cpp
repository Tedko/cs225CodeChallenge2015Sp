#include "image.h"

void Image::flipleft	()
{
//runs nicely

  for (size_t yi = 0; yi < height(); yi++)
{
  for (size_t xi = 0; xi < width()/2; xi++)
  {
    RGBAPixel *pOld = operator()(xi, yi);
      RGBAPixel *pNew = operator()(width()-xi-1,yi);
      RGBAPixel *pTemp = new RGBAPixel;

      pTemp->red  = pOld->red;
      pTemp->green  = pOld->green;
      pTemp->blue  = pOld->blue;
      pOld->red  = pNew->red;
      pOld->green  = pNew->green;
      pOld->blue  = pNew->blue;
      pNew->red  = pTemp->red;
      pNew->green  = pTemp->green;
      pNew->blue  = pTemp->blue;




delete pTemp;
pNew=NULL;
pOld=NULL;
pTemp=NULL;

      //delete pNew;
      //delete pOld;


  }
}


}

void Image::adjustbrightness	(	int 	r,int 	g,int 	b )
{




  for (size_t yi = 0; yi < height(); yi++)
{
  for (size_t xi = 0; xi < width(); xi++)
  {
    RGBAPixel *p = operator()(xi, yi);





      int newRed  = p->red+r;
      int newGreen  = p->green+g;
      int newBlue   = p->blue+b;


if (0 <= newRed &  newRed <= 255){p->red=newRed;}
  else if(0 > newRed){p->red=0;}
  else{p->red=255;}

if (0 <= newGreen & 255 >= newGreen){p->green=newGreen;}
  else if(0 > newGreen){p->green=0;}
  else{p->green=255;}

if (0 <= newBlue & 255 >= newBlue){p->blue=newBlue;}
  else if(0 > newBlue){p->blue=0;}
  else{p->blue=255;}

  p=NULL;


    }
  }

  //delete p;



}

void Image::invertcolors	()
{

//runs correct

  for (size_t yi = 0; yi < height(); yi++)
  {
  for (size_t xi = 0; xi < width(); xi++)
  {
    RGBAPixel *p = operator()(xi, yi);


    p->red  = 255 - p->red;
    p->green  = 255 - p->green;
    p->blue  = 255 - p->blue;


    //delete p;
    p=NULL;


  }

  }

}
