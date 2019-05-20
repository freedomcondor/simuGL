#include "BirdCtrl.h"
#include "Bird.h"

int setspeed(lua_State *L);
int setneighbour(lua_State *L);

static const luaL_Reg funcs_bird[] = 
{
	{"setspeed", setspeed},
	{NULL, NULL},
};

int BirdCtrl::load(Bird* _bird, char const str[])
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

int lua_setTableNeighbour(lua_State *L, int i, struct neighbour _nei)
{
	lua_pushnumber(L, i);
	lua_newtable(L);

		lua_setTableVector3(L, "loc", _nei.loc);
		lua_setTableVector3(L, "speed", _nei.speed);
		lua_setTableQuaternion(L, "dir", _nei.dir);

	lua_settable(L, -3);
}

int setneighbour(lua_State *L)
{
	lua_getglobal(L, "_bird");
	Bird* bird = (Bird*)lua_touserdata(L,-1);

	lua_getglobal(L, "bird");
	lua_pushstring(L, "neighbours");
		lua_newtable(L);
			lua_setTableNumber(L, "n", bird->nNeighbours);

			for (int i = 0; i < bird->nNeighbours; i++)
				lua_setTableNeighbour(L, i+1, bird->neighbours[i]);
	lua_settable(L, -3);
	lua_pop(L,1); //pop bird
	return 0;
}

