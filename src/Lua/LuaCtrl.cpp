#include "LuaCtrl.h"

LuaCtrl::LuaCtrl()
{
	L = luaL_newstate();
	luaL_openlibs(L);
	lua_settop(L, 0);
}

LuaCtrl::~LuaCtrl()
{
	lua_close(L);
}

int LuaCtrl::load(char const str[])
{
	if ((luaL_loadfile(L, str)) || (lua_pcall(L, 0,0,0)))
	{
		printf("load file %s fail %s\n", str, lua_tostring(L, -1));
		return -1;
	}

	loaded = true;
	return 0;
}

int LuaCtrl::init()
{
	if (loaded == false) return -1;
	lua_getglobal(L, "init");
	if (lua_pcall(L, 0,0,0) != 0)
	{
		printf("call init func fail %s\n", lua_tostring(L, -1));
		return -1;
	}
	return 0;
}

int LuaCtrl::step(double time)
{
	if (loaded == false) return -1;
	lua_getglobal(L, "step");
	lua_pushnumber(L, time);
	if (lua_pcall(L, 1,0,0) != 0)
	{
		printf("call step func fail %s\n", lua_tostring(L, -1));
		return -1;
	}

	return 0;
}

int LuaCtrl::exit()
{
	if (loaded == false) return -1;
	lua_getglobal(L, "exit");
	if (lua_pcall(L, 0,0,0) != 0)
	{
		printf("call exit func fail %s\n", lua_tostring(L, -1));
		return -1;
	}

	return 0;
}

int lua_setTableNumber(lua_State *L, char const str[], double x)
{
	lua_pushstring(L, str);
	lua_pushnumber(L, x);
	lua_settable(L, -3);
	return 0;
}

double lua_getTableNumber(lua_State *L, char const str[])
{
	lua_pushstring(L, str);
	lua_gettable(L,-2);	
	double n = luaL_checknumber(L,-1);
	lua_pop(L,1);
	return n;
}

int lua_getTableVector3(lua_State *L, char const str[], Vector3& v)
{
	lua_pushstring(L, str);
	lua_gettable(L,-2);
	lua_toVector3(L, v);
	return 0;
}

int lua_setTableVector3(lua_State *L, char const str[], Vector3& v)
{
	lua_pushstring(L, str);
	lua_newtable(L);
	lua_setTableNumber(L, "x", v.x);
	lua_setTableNumber(L, "y", v.y);
	lua_setTableNumber(L, "z", v.z);
	lua_settable(L, -3);
}

int lua_setTableQuaternion(lua_State *L, char const str[], Quaternion& q)
{
	lua_pushstring(L, str);
	lua_newtable(L);
	lua_setTableNumber(L, "x", q.l.x);
	lua_setTableNumber(L, "y", q.l.y);
	lua_setTableNumber(L, "z", q.l.z);
	lua_setTableNumber(L, "w", q.w);
	lua_settable(L, -3);
}


int lua_toVector3(lua_State *L, Vector3& v)
{
		// assuming the vector table is already on stack top
	double x = lua_getTableNumber(L, "x");
	double y = lua_getTableNumber(L, "y");
	double z = lua_getTableNumber(L, "z");
	v.set(x,y,z);
	lua_pop(L,1);
	return 0;
}
