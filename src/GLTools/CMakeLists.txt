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
