set(simu_include_dirs 
	${simu_include_dirs}
	${CMAKE_CURRENT_SOURCE_DIR}
	PARENT_SCOPE
)

set(simu_cpps
	${simu_cpps}
	${CMAKE_CURRENT_SOURCE_DIR}/LuaCtrl.cpp
	PARENT_SCOPE
)
