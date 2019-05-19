#ifndef BIRDCTRL
#define BIRDCTRL

class Bird;
#include "LuaCtrl.h"

class BirdCtrl : public LuaCtrl
{
	public:
	int load(Bird* _bird, char str[]);
	int init();
	int step(double time);
	int exit();
};

#endif
