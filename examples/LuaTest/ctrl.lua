package.path = package.path .. ";" .. SIMU_LUA_DIR .. "/?.lua"

Vec3 = require("Vector3")
Qua = require("Quaternion")

function init()
	print("I am init")
	local q1 = Qua:createFrom4Vector3s(Vec3(1,0,0), 
	                                   Vec3(0,1,0),
	                                   Vec3(1,1,0),
	                                   Vec3(-1,1,1)
	                                  )
	print(q1:getAxis())
	print(q1:getAng())
	print(q1:toRotate(Vec3(0,0,1)))
end

function step()
	print(SIMU_LUA_DIR)
	print(Vec3(0,0,0))
	print(Qua(0,0,1,math.pi):toRotate(Vec3(0,0,0)))
	print("I am step")
end

function exit()
	print("I am exit")
end
