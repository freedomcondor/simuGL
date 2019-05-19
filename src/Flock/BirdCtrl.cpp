#include "BirdCtrl.h"
#include "Bird.h"

int setspeed(lua_State *L);
int setneighbour(lua_State *L);

static const luaL_Reg funcs_bird[] = 
{
	{"setspeed", setspeed},
	{NULL, NULL},
};

int BirdCtrl::load(Bird* _bird, char str[])
{
	lua_pushlightuserdata(L,(void*)_bird); 
	lua_setglobal(L, "_bird");

	lua_newtable(L);
	luaL_setfuncs(L, funcs_bird, 0);
	lua_setglobal(L, "bird");
	return LuaCtrl::load(str);
}

int BirdCtrl::init()
{
	if (loaded == false) return -1;
	return LuaCtrl::init();
}

int BirdCtrl::step(double time)
{
	setneighbour(L);
	if (loaded == false) return -1;
	return LuaCtrl::step(time);
}

int BirdCtrl::exit()
{
	if (loaded == false) return -1;
	return LuaCtrl::exit();
}

/*-------------------------------------*/
int setspeed(lua_State *L)
{
	Vector3 v;
	lua_toVector3(L, v);

	lua_getglobal(L, "_bird");
	Bird* bird = (Bird*)lua_touserdata(L,-1);
	bird->setspeed(v);
	return 0;
}

int setneighbour(lua_State *L)
{
	lua_getglobal(L, "_bird");
	Bird* bird = (Bird*)lua_touserdata(L,-1);

	lua_getglobal(L, "bird");
	lua_pushstring(L, "neighbours");
	lua_newtable(L);
		lua_setTableNumber(L, "n", bird->nNeighbours);
	lua_settable(L, -3);
	lua_pop(L,1); //pop bird
	return 0;
}

