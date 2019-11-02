set(simu_include_dirs 
	${simu_include_dirs}
	${CMAKE_CURRENT_SOURCE_DIR}
	PARENT_SCOPE
)

set(simu_definitions
	${simu_definitions}
	-DFLOCK_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\"
	PARENT_SCOPE
)

set(simu_cpps
	${simu_cpps}
	${CMAKE_CURRENT_SOURCE_DIR}/Bird.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/BirdCtrl.cpp
	PARENT_SCOPE
)
