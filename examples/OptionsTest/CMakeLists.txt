cmake_minimum_required(VERSION 3.5)

set(simu_Lua on)
set(simu_Math on)
set(simu_Tools on)
add_subdirectory(../../src
                 ${CMAKE_CURRENT_BINARY_DIR}/simuGL
)

add_definitions(
	${simu_definitions}
)

add_executable(main 
	${simu_cpps}
	MainLoop.cpp
)

include_directories( 
	${simu_include_dirs}
)

target_link_libraries(main 	
	${simu_link_libraries}
)
