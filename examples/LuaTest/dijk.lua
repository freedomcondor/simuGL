package.path = package.path .. ";" .. SIMU_LUA_DIR .. "/?.lua"

Dijk = require("Dijkstra")
DMSG = require("DebugMessage")
DMSG.enable()

function init()
	local D, L = Dijk{
	--[[
	           1.1,1 -- two road from 2 to 4
	        2 ------ 4
	      /   \   /    \99
	     /0    \ / 1    \
	    1       =        6
	     \99   / \ 5    /
	      \   /   \    /0
	        3 ------ 5
	             2
	--]]
	--	1		2		3		4		5		6
	 {	0,		0,		99,		nil,	nil,	nil},
	 {	0,		0,		nil,	{1.1,1},	5,		nil},
	 {	99,		nil,	0,		1,		2,		nil},
	 {	nil,	{1.1,1},	1,		0,		nil,	99},
	 {	nil,	5,		2,		nil,	0,		0},
	 {	nil,	nil,	nil,	99,		0,		0},
	}

	DMSG("D")
	DMSG(D)
	DMSG("L")
	DMSG(L)
end

function step()
end

function exit()
end
