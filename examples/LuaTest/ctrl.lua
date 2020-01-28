package.path = package.path .. ";" .. SIMU_LUA_DIR .. "/?.lua"

Vec3 = require("Vector3")
Qua = require("Quaternion")
Arrangement = require("Arrangement")
require("Debugger")

local arranger
function init()
	print("I am init")
	print(SIMU_LUA_DIR)
	print("--- vector quaternion test ---")
	local q1 = Qua:createFrom4Vector3s(Vec3(1,0,0), 
	                                   Vec3(0,1,0),
	                                   Vec3(1,1,0),
	                                   Vec3(-1,1,1)
	                                  )
	print(q1:getAxis())
	print(q1:getAng())
	print(q1:toRotate(Vec3(0,0,1)))

	print("--- arranger test ---")
	arranger = Arrangement:newArranger{1, "aaa", {"nihao"}, 4, 5}
	local aa = arranger()
	while aa ~= nil do
		for i = 1, #aa do print(i, aa[i]) end
		print("---")
		aa = arranger()
	end
end

function step()
	print("I am step")
	print("--- vector quaternion test ---")
	print(Vec3(0,0,0))
	print(Qua(0,0,1,math.pi):toRotate(Vec3(0,0,0)))
end

function exit()
	print("I am exit")
end
