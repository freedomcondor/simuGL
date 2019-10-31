cmake_minimum_required(VERSION 3.5)

add_subdirectory(../../src/Math
                 ${CMAKE_CURRENT_BINARY_DIR}/simuGL/Math
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
