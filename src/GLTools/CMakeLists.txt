#------ system detect ----------------------------------#
MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	MESSAGE(STATUS "current platform: Linux ")
	SET(platform_flag -DSIMU_ON_LINUX)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	MESSAGE(STATUS "current platform: Windows")
	SET(platform_flag -DSIMU_ON_WINDOWS)
	SET(CMAKE_EXE_LINKER_FLAGS "/SAFESEH:NO")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
	MESSAGE(STATUS "current platform: Darwin(mac?)")
	SET(PlatformFlag -DSIMU_ON_APPLE)
	SET(simu_include_dirs 
		${simu_include_dirs}
		-DGL_SILENCE_DEPRECATION
		PARENT_SCOPE
	)
ELSE ()
	MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
	SET(platform_flag -DSIMU_ON_UNKNOWNPLATFORM)
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

set(simu_definitions
	${simu_definitions}
	${platform_flag}
	PARENT_SCOPE
)

#--- add OpenGL --------------------------------------------#

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

#--- set variables -----------------------------------------#
set(simu_include_dirs 
	${simu_include_dirs}
	${CMAKE_CURRENT_SOURCE_DIR}
	${OPENGL_INCLUDE_DIRS}
	${GLUT_INCLUDE_DIRS}
	PARENT_SCOPE
)

set(simu_cpps
	${simu_cpps}
	${CMAKE_CURRENT_SOURCE_DIR}/MainGL.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/DrawFunction.cpp
	PARENT_SCOPE
)

set(simu_link_libraries 
	${simu_link_libraries}
	${OPENGL_LIBRARIES}
	${GLUT_LIBRARY}
	PARENT_SCOPE
)
