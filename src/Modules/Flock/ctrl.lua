package.path = package.path .. ";" .. SIMU_LUA_DIR .. "/?.lua"

local Vec3 = require("Vector3")
local Quaternion = require("Quaternion")

function init()
	print("i am init")
	--math.randomseed(1)
end

function step(time)
	-- create vector3s
	for i, nei in ipairs(bird.neighbours) do
		nei.loc = Vec3:create(nei.loc.x, nei.loc.y, nei.loc.z)
		nei.speed = Vec3:create(nei.speed.x, nei.speed.y, nei.speed.z) 
	end

	testModel(time)
	--zonesModel(time)
	--vicsekModel(time)
end

function exit()
	print("i am exit")
end

function testModel(time)
	local sumspeed = Vec3:create()
	local speed = Vec3:create(math.random(0,1),
	                          math.random(-1,1),
	                          math.random(-1,1)):nor() * 0.010

	for i, nei in ipairs(bird.neighbours) do
		speed = speed + nei.loc:nor() * (nei.loc:len() - bird.sight * 0.7) * math.random(0.7, 1.3)
		sumspeed = sumspeed + nei.speed
	end
	speed = speed + sumspeed / bird.neighbours.n
	bird.setspeed(speed)
end

function vicsekModel(time)
	local speed = Vec3:create(math.random(0,1),
	                          math.random(-1,1),
	                          math.random(-1,1)):nor() * 0.10
	sum = Vec3:create()
	count = 0
	for i, nei in ipairs(bird.neighbours) do
		count = count + 1
		sum = sum + nei.speed
	end
	if count ~= 0 then
		speed = speed + sum / count
	end
	bird.setspeed(speed)
end

function zonesModel(time)
	local speed = Vec3:create(math.random(0,1),
	                          math.random(-1,1),
	                          math.random(-1,1)):nor() * 0.0010


	local zor = bird.sight * 0.2
	local zoo = bird.sight * 0.8

	-- zone of repulsive
	local count = 0
	local sum = Vec3:create()
	for i, nei in ipairs(bird.neighbours) do
		if nei.loc:len() <= zor then
			count = count + 1
			sum = sum + nei.loc:nor()
		end
	end
	if count ~= 0 then
		sum = -sum --/ count
		speed = speed + sum
		bird.setspeed(speed)
		return 
	end

	-- zone of orientation
	sum = Vec3:create()
	count = 0
	for i, nei in ipairs(bird.neighbours) do
		if nei.loc:len() > zor and nei.loc:len() < zoo then
			count = count + 1
			sum = sum + nei.speed:nor()
		end
	end
	if count ~= 0 then
		--sum = sum / count
		speed = speed + sum
	end

	-- zone of attractive
	sum = Vec3:create()
	count = 0
	for i, nei in ipairs(bird.neighbours) do
		if nei.loc:len() > zoo then
			count = count + 1
			sum = sum + nei.loc:nor()
		end
	end
	if count ~= 0 then
		--sum = sum / count
		speed = speed + sum
	end
	bird.setspeed(speed*0.1)
end
