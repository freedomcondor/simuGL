package.path = package.path .. ";" .. SIMU_LUA_DIR .. "/?.lua"

MinCostFlowNetwork = require("MinCostFlowNetwork")
DMSG = require("DebugMessage")
DMSG.enable()

function init()
	--[[
	         inf, 1.1
	        2 ------ 4
	   5,0/   \   /    \3,0
	     /     \ / 1    \
	    1       =        6
	     \     / \ 5    /
	   3,0\   /   \    /5,0
	        3 ------ 5
	             2
	--]]

	local W = {
	--	1		2		3		4		5		6
	 {	0,		0,		0,		nil,	nil,	nil},
	 {	0,		0,		nil,	1.1,	5,		nil},
	 {	0,		nil,	0,		1,		2,		nil},
	 {	nil,	1.1,	1,		0,		nil,	0},
	 {	nil,	5,		2,		nil,	0,		0},
	 {	nil,	nil,	nil,	0,		0,		0},
	}

	local INF = 1 / 0
	local C = {
	 {	nil,	5,		3,		nil,	nil,	nil},
	 {	nil,	nil,	nil,	INF,	INF,	nil},
	 {	nil,	nil,	nil,	INF,	INF,	nil},
	 {	nil,	nil,	nil,	nil,	nil,	3},
	 {	nil,	nil,	nil,	nil,	nil,	5},
	 {	nil,	nil,	nil,	nil,	nil,	nil},
	}

	local f = MinCostFlowNetwork(C, W)

	DMSG("f")
	DMSG(f)
end

function step()
end

function exit()
end
