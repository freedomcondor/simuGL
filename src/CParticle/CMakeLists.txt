set(simu_include_dirs 
	${simu_include_dirs}
	${CMAKE_CURRENT_SOURCE_DIR}
	PARENT_SCOPE
)

set(simu_cpps
	${simu_cpps}
	${CMAKE_CURRENT_SOURCE_DIR}/QParticle.cpp	
	${CMAKE_CURRENT_SOURCE_DIR}/Object.cpp	
	${CMAKE_CURRENT_SOURCE_DIR}/Box.cpp	
	${CMAKE_CURRENT_SOURCE_DIR}/Sphere.cpp	
	${CMAKE_CURRENT_SOURCE_DIR}/Cylinder.cpp
	#${CMAKE_CURRENT_SOURCE_DIR}/Convexhull.cpp
	#${CMAKE_CURRENT_SOURCE_DIR}/DBox.cpp	
	PARENT_SCOPE
)
