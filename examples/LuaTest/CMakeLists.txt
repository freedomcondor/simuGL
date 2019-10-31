cmake_minimum_required(VERSION 3.5)

add_subdirectory(../../src/CVector
                 ${CMAKE_CURRENT_BINARY_DIR}/simuGL/CVector
)

add_subdirectory(../../src/Lua
                 ${CMAKE_CURRENT_BINARY_DIR}/simuGL/Lua
)

add_executable(main 
	${simu_cpps}
	main.cpp
)

include_directories( 
	${simu_include_dirs}
)

target_link_libraries(main 	
	${simu_link_libraries}
)
