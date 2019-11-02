package.path = package.path .. ";" .. SIMU_LUA_DIR .. "/?.lua"

Vector3 = require("Vector3")

function init()
	print("I am init")
end

function step()
	print(simu_lua_src)
	print(Vector3:create(0,0,0))
	print("I am step")
end

function exit()
	print("I am exit")
end
