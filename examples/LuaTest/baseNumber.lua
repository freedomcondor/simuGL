package.path = package.path .. ";" .. SIMU_LUA_DIR .. "/?.lua"

BaseNumber = require("BaseNumber")
DMSG = require("DebugMessage")
DMSG.enable()

function init()
	local a = BaseNumber:create(300, {1, -1})
	local b = BaseNumber:createWithInc(300, 2)
	print("a = ", a + 0)
	print("b = ", 0 + b)
	print("c = ", a > -b)
end

function step()
end

function exit()
end
