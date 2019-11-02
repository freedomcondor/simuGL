#-----------------------------------------------------------#
#    add Lua                                                #
#-----------------------------------------------------------#
find_package(Lua REQUIRED)
MESSAGE(STATUS "MSG: lua inc: ${LUA_INCLUDE_DIR}")  
MESSAGE(STATUS "MSG: lua lib: ${LUA_LIBRARIES}")  

set(simu_definitions
	${simu_definitions}
	-DSIMU_LUA_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\"
	PARENT_SCOPE
)

set(simu_include_dirs 
	${simu_include_dirs}
	${CMAKE_CURRENT_SOURCE_DIR}
	${LUA_INCLUDE_DIR}
	PARENT_SCOPE
)

set(simu_cpps
	${simu_cpps}
	${CMAKE_CURRENT_SOURCE_DIR}/LuaCtrl.cpp
	PARENT_SCOPE
)

set(simu_link_libraries 
	${simu_link_libraries}
	${LUA_LIBRARIES}
	PARENT_SCOPE
)

