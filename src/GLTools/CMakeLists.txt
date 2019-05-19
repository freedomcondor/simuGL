set(simu_include_dirs 
	${simu_include_dirs}
	${CMAKE_CURRENT_SOURCE_DIR}
	PARENT_SCOPE
)

set(simu_cpps
	${simu_cpps}
	${CMAKE_CURRENT_SOURCE_DIR}/MainGL.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/DrawFunction.cpp
	PARENT_SCOPE
)
