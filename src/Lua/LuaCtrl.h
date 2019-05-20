#ifndef LUACTRL
#define LUACTRL

#include <lua.hpp>
#include "Vector3.h"
#include "Quaternion.h"

class LuaCtrl
{
	public:
	lua_State *L;
	int loaded = false;

	LuaCtrl();
	~LuaCtrl();

	int load(char const str[]);
	int init();
	int step(double time);
	int exit();
	
};

double lua_getTableNumber(lua_State *L, char const str[]);
int lua_setTableNumber(lua_State *L, char const str[], double x);

int lua_getTableVector3(lua_State *L, char const str[], Vector3& v);
int lua_setTableVector3(lua_State *L, char const str[], Vector3& v);
int lua_toVector3(lua_State *L, Vector3& v);

int lua_setTableQuaternion(lua_State *L, char const str[], Quaternion& q);

		// assume the vector table is already on stack top

#endif
