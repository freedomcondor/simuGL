vim coding.sh -c "
	tabnew CMakeLists.txt

	tabnew src/GLTools/GLTools.h
	vsp src/MainLoop.cpp

	tabnew src/Flock/Bird.h
	vsp src/Flock/Bird.cpp

	tabnew src/Flock/BirdCtrl.h
	vsp src/Flock/BirdCtrl.cpp

	tabnew src/Lua/LuaCtrl.h
	vsp src/Lua/LuaCtrl.cpp

	tabnew src/GLTools/DrawFunction.cpp
	vsp src/GLTools/MainGL.cpp
"	
<<COMMENT
	tabnew src/CParticle/QParticle.h
	vsp src/CParticle/QParticle.cpp

	tabnew src/CParticle/Object.h
	vsp src/CParticle/Object.cpp

	tabnew src/CParticle/Convexhull.h
	vsp src/CParticle/Convexhull.cpp
COMMENT
