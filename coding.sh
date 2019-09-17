vim coding.sh -c "
	tabnew CMakeLists.txt

	tabnew src/GLTools/DrawFunction.cpp
	vsp src/GLTools/MainGL.cpp

	tabnew src/GLTools/GLTools.h
	vsp src/MainLoop.cpp

	tabnew src/test/solve_MainLoop.cpp
	tabnew src/Math/Solve.h
	vsp src/Math/Solve.c
"	
<<COMMENT
	tabnew src/test/list_MainLoop.cpp
	tabnew src/Tools/List.h
	vsp src/Tools/List.cpp

	tabnew src/test/flock_MainLoop.cpp
	tabnew src/Modules/Flock/Bird.h
	vsp src/Modules/Flock/Bird.cpp

	tabnew src/Modules/Flock/BirdCtrl.h
	vsp src/Modules/Flock/BirdCtrl.cpp
	tabnew src/Modules/Flock/ctrl.lua

	tabnew src/Lua/LuaCtrl.h
	vsp src/Lua/LuaCtrl.cpp

	tabnew src/test/solve_MainLoop.cpp
	tabnew src/Math/Solve.h
	vsp src/Math/Solve.c

	tabnew src/CParticle/QParticle.h
	vsp src/CParticle/QParticle.cpp

	tabnew src/CParticle/Object.h
	vsp src/CParticle/Object.cpp

	tabnew src/CParticle/Convexhull.h
	vsp src/CParticle/Convexhull.cpp
COMMENT
