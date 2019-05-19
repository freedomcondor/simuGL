function init()
	print("i am init")
end

function step(time)
	bird.setspeed({x = 0, y = 0, z = 0.01})
	print("test = ", bird.neighbours.n);
end

function exit()
	print("i am exit")
end
