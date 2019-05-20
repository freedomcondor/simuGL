function init()
	print("i am init")
end

function step(time)
	bird.setspeed({x = 0, y = 0, z = 0.01})
	print("test = ", bird.neighbours.n);
	for i, v in ipairs(bird.neighbours) do
		print("bird", i);
		print("\tloc ");
		print("\t\t", v.loc.x, v.loc.y, v.loc.z);
		print("\tspeed ");
		print("\t\t", v.speed.x, v.speed.y, v.speed.z);
	end
end

function exit()
	print("i am exit")
end
