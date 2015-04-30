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
								ofstream myfile("exampleAABXXB.txt");


								//myfile.close();
								Image* myImage = new Image();
								myImage->readFromFile("in.png");
								for(size_t yi=0; yi<myImage->height(); yi++)
								{
																for(size_t xi=0; xi<myImage->width(); xi++)
																{
																								int G= (*myImage)(xi, yi)->green;
																								int R= (*myImage)(xi, yi)->red;
																								int B= (*myImage)(xi, yi)->blue;


																								if(G> 176 && G < 196)
																																if(R < 110  && R>90  )
																																								if(B < 115 & B>95)
																																								{
																																																if(myfile.is_open())
																																																{
																																																								myfile<<xi<<","<<yi;
																																																								myfile <<": "<<(int)(*myImage)(xi, yi)->red<<" "<<(int)(*myImage)(xi, yi)->green<<" "<<(int)(*myImage)(xi, yi)->blue<<endl;

																																																}
																																								}
																}
								}

								//myImage->writeToFile("out.png");
								myfile.close();

								//delete myImage;

								return 0;
}
