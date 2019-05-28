local srcpath = "../src/"
local luapath = srcpath .. "Lua/"
package.path = package.path .. ";" .. luapath .. "?.lua"

local Vec3 = require("Vector3")
local Quaternion = require("Quaternion")

function init()
	print("i am init")
	--math.randomseed(1)
end

function step(time)
	local sumspeed = Vec3:create()
	local speed = Vec3:create(math.random(0,1),
	                          math.random(-1,1),
	                          math.random(-1,1)):nor() * 0.010

	for i, nei in ipairs(bird.neighbours) do
		nei.loc = Vec3:create(nei.loc.x, nei.loc.y, nei.loc.z)
		nei.speed = Vec3:create(nei.speed.x, nei.speed.y, nei.speed.z) 
		speed = speed + nei.loc:nor() * (nei.loc:len() - bird.sight * 0.7) * math.random(0.7, 1.3)

		sumspeed = sumspeed + nei.speed
	end
	speed = speed + sumspeed / bird.neighbours.n
	bird.setspeed(speed)
end

function exit()
	print("i am exit")
end
