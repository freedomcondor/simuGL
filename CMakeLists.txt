cmake_minimum_required(VERSION 3.5)

project(debugGL)

#-----------------------------------------------------------#
#    system detect                                          #
#-----------------------------------------------------------#
MESSAGE(STATUS "MSG: operation system is ${CMAKE_SYSTEM}")  
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")  
	MESSAGE(STATUS "MSG: current platform: Linux ")  
	#add_definitions(-Dlinux)

ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")  
	MESSAGE(STATUS "MSG: current platform: Windows")  
	add_definitions(-Dwindows)
	SET(CMAKE_EXE_LINKER_FLAGS "/SAFESEH:NO")

ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")  
	MESSAGE(STATUS "MSG: current platform: FreeBSD")  

ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")  
	MESSAGE(STATUS "MSG: current platform: Darwin(mac?)")  
	add_definitions(-Dmac)

ELSE ()  
	MESSAGE(STATUS "MSG: other platform: ${CMAKE_SYSTEM_NAME}")  
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")  


#-----------------------------------------------------------#
#    add OpenGL                                             #
#-----------------------------------------------------------#
IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
#my windows does not need to find package
ELSE()
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
MESSAGE(STATUS "MSG: opengl inc: ${OPENGL_INCLUDE_DIRS}")  
MESSAGE(STATUS "MSG: opengl lib: ${OPENGL_LIBRARIES}")  
MESSAGE(STATUS "MSG: glut inc: ${GLUT_INCLUDE_DIRS}")  
MESSAGE(STATUS "MSG: glut lib: ${GLUT_LIBRARY}")  

#-----------------------------------------------------------#
#    add Lua                                                #
#-----------------------------------------------------------#
find_package(Lua REQUIRED)
MESSAGE(STATUS "MSG: lua inc: ${LUA_INCLUDE_DIR}")  
MESSAGE(STATUS "MSG: lua lib: ${LUA_LIBRARIES}")  

#-----------------------------------------------------------#
#    set compilation                                        #
#-----------------------------------------------------------#
set(CMAKE_BUILD_TYPE Debug)

add_executable(main 
	src/MainLoop.cpp

	src/GLTools/MainGL.cpp
	src/GLTools/DrawFunction.cpp

	src/CVector/Vector3.cpp
	src/CVector/Matrix3.cpp
	src/CVector/Quaternion.cpp

	src/CParticle/QParticle.cpp	
	src/CParticle/Object.cpp	
	src/CParticle/Box.cpp	
	src/CParticle/Sphere.cpp	
	src/CParticle/Cylinder.cpp
	src/CParticle/Convexhull.cpp
	src/CParticle/DBox.cpp	

	src/Robot/Manipulator.cpp	

	src/CWorld/ChessWorld.cpp	
	src/CellularAutomaton/CellularAutomaton.cpp
)

include_directories(
	${OPENGL_INCLUDE_DIRS} 
	${GLUT_INCLUDE_DIRS}
	${LUA_INCLUDE_DIR}
	src/GLTools
	src/CVector
	src/CParticle
	src/Robot
	src/CWorld
	src/CellularAutomaton
)

target_link_libraries(main 	
	${OPENGL_LIBRARIES} 
	${GLUT_LIBRARY}
	${LUA_LIBRARIES}
)
