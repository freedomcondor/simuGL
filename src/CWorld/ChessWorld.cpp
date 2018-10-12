#include "ChessWorld.h"

ChessWorld::ChessWorld()
{
}

int ChessWorld::set(int x, int y, int z, double value)
{
	return aworld.set(x,y,z,value);
}

double ChessWorld::get(int x, int y, int z)
{
	return aworld.get(x,y,z);
}
