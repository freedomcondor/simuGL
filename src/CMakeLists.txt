cmake_minimum_required(VERSION 3.5)

#------ include necessaries ---------------------------#
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/GLTools)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CVector)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Objects)
set(simu_cpps
	${simu_cpps}
	${CMAKE_CURRENT_SOURCE_DIR}/GLTools/DrawObjects.cpp
)

#------ Options ---------------------------------------#
if (simu_Lua)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Lua)
endif (simu_Lua)

if (simu_Math)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Math)
endif (simu_Math)

if (simu_Tools)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Tools)
endif (simu_Tools)

#------ set variables ---------------------------------#
set(simu_definitions
	${simu_definitions}
	PARENT_SCOPE
)

set(simu_include_dirs 
	${simu_include_dirs}
	PARENT_SCOPE
)

set(simu_cpps
	${simu_cpps}
	PARENT_SCOPE
)

set(simu_link_libraries 
	${simu_link_libraries}
	PARENT_SCOPE
)
