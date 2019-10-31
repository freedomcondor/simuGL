#include <stdio.h>

#include "LuaCtrl.h"

int main()
{
	LuaCtrl a;

	a.load("../ctrl.lua");
	a.init();
	for (int i = 0; i < 5; i++)
		a.step(0.2);
	a.exit();

	return 0;
}
