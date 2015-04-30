EXENAME1 = testscene
EXENAME2 = testimage

OBJS1 = image.o png.o rgbapixel.o scene.o testscene.o
OBJS2 = testimage.o image.o png.o rgbapixel.o

 
CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi

all : $(EXENAME2) $(EXENAME1)

$(EXENAME2) : $(OBJS2)
	$(LD) $(OBJS2) $(LDFLAGS) -o testimage

$(EXENAME1): $(OBJS1)
	$(LD) $(OBJS1) $(LDFLAGS) -o testscene

testimage.o : testimage.cpp png.h rgbapixel.h
	$(CXX) $(CXXFLAGS) testimage.cpp

testscene.o : testscene.cpp png.h  scene.h image.h
	$(CXX) $(CXXFLAGS) testscene.cpp

scene.o : scene.cpp scene.h image.h png.h
	$(CXX) $(CXXFLAGS) scene.cpp

png.o : png.h png.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.h rgbapixel.cpp
	$(CXX) $(CXXFLAGS) rgbapixel.cpp

image.o : image.h image.cpp
	$(CXX) $(CXXFLAGS) image.cpp

clean :
	-rm *.o testimage testscene

