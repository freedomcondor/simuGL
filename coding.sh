vim coding.sh -c "
	tabnew CMakeLists.txt

	tabnew src/CParticle/QParticle.h
	vsp src/CParticle/QParticle.cpp

	tabnew src/CParticle/Object.h
	vsp src/CParticle/Object.cpp

	tabnew src/CParticle/Convexhull.h
	vsp src/CParticle/Convexhull.cpp

	tabnew src/GLTools/DrawFunction.cpp
	vsp src/GLTools/MainGL.cpp

	tabnew src/GLTools/GLTools.h
	vsp src/MainLoop.cpp
"
