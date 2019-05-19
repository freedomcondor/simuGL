#ifndef LUACTRL
#define LUACTRL

#include <lua.hpp>
#include "Vector3.h"

class LuaCtrl
{
	public:
	lua_State *L;
	int loaded = false;

	LuaCtrl();
	~LuaCtrl();

	int load(char str[]);
	int init();
	int step(double time);
	int exit();
	
};

double lua_getTableNumber(lua_State *L, char str[]);
int lua_setTableNumber(lua_State *L, char str[], double x);
int lua_getTableVector3(lua_State *L, char str[], Vector3& v);
int lua_toVector3(lua_State *L, Vector3& v);
		// assume the vector table is already on stack top

#endif
