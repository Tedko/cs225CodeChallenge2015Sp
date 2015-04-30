/**********************************************************
 * testimage.cpp -- part of CS225 MP2
 *
 * This file performs some basic tests of the Image class.
 * It is not intended to catch every possible error.You may
 * modifty this or write your own testimage.cpp to perform
 * additional tests.
 *
 *   Author: Jonathan Ray
 *   Date: 02 Feb 2007
 */
#include <fstream>
#include "image.h"

using namespace std;
int main()
{
								//ofstream myfile("exampleAABxxxxXXB.txt");


								//myfile.close();
								Image* myImage = new Image();
								Image* NewImage = new Image();

								myImage->readFromFile("in.png");
								NewImage->readFromFile("static.png");

/*
        if(myfile.is_open())
        {
                //myfile<<xi<<","<<yi;
                myfile <<": "<<(int)(*myImage)(202, 227)->red<<" "<<(int)(*myImage)(202, 227)->green<<" "<<(int)(*myImage)(202, 227)->blue<<endl;

        }
 */
								for(int i=0; i<17; i++)
								{
																for(size_t yi=0; yi<myImage->height(); yi++)
																{
																								for(size_t xi=0; xi<myImage->width(); xi++)
																								{
																																int G= (*NewImage)(xi, yi)->green;
																																int R= (*NewImage)(xi, yi)->red;
																																int B= (*NewImage)(xi, yi)->blue;
																																(*myImage)(xi,yi)->green+=G;
																																(*myImage)(xi,yi)->red+=R;
																																(*myImage)(xi,yi)->blue+=B;

																								}
																}
								}
								myImage->writeToFile("outPu.png");


								//myImage->writeToFile("out.png");
								//myfile.close();

								//delete myImage;

								return 0;
}
