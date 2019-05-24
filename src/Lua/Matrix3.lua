----------------------------------------
-- Weixu Zhu
-- 		zhuweixu_harry@126.com
-- 	Version 1.1:	02/04/2019
-- 		add reverse and adj
--
-- 	not perfect, use with caution
----------------------------------------
Vec3 = require("Vector3")
local Matrix3 = {CLASS = "Matrix3"}
Matrix3.__index = Matrix3

function Matrix3:create(Matconfig,x12,x13,x21,x22,x23,x31,x32,x33)
	local instance = {}
	setmetatable(instance, self)
	self.__index = self

		--the metatable of instance would be whoever owns this create
			--so you can :  a = State:create();  b = a:create();  grandfather-father-son
	
	-- Asserts
	-- to be filled

	instance.n = 3	
	instance.m = 3

	if type(Matconfig) == "table" then
		for i = 1,3 do
			instance[i] = {}
			for j = 1,3 do
				instance[i][j] = Matconfig[i][j] or 0
			end
		end
		return instance
	end

	if 	type(Matconfig) == "number" and type(x12) == "number" and type(x13) == "number" and
		type(x21) == "number" and type(x22) == "number" and type(x23) == "number" and
		type(x31) == "number" and type(x32) == "number" and type(x33) == "number" then

		instance[1] = {Matconfig,x12,x13}
		instance[2] = {x21,x22,x23}
		instance[3] = {x31,x32,x33}
		return instance
	end

	instance[1] = {0,0,0}
	instance[2] = {0,0,0}
	instance[3] = {0,0,0}

	return instance
end

function Matrix3.__add(a,b)
	local c = Matrix3:create()
	for i = 1,3 do
		for j = 1,3 do
			c[i][j] = a[i][j] + b[i][j]
		end
	end

	return c
end

function Matrix3.__unm(b)
	local c = Matrix3:create()
	for i = 1,3 do
		for j = 1,3 do
			c[i][j] = -b[i][j]
		end
	end

	return c
end

function Matrix3.__sub(a,b)
	local c = Matrix3:create(-b)
	c = c + a

	return c
end

function Matrix3.__mul(a,b)
	if 	type(a) == "table" and a.CLASS == "Matrix3" and 
		type(b) == "table" and b.CLASS == "Vector3" then
		local c = Vec3:create()
		c.x = a[1][1] * b.x + a[1][2] * b.y + a[1][3] * b.z
		c.y = a[2][1] * b.x + a[2][2] * b.y + a[2][3] * b.z
		c.z = a[3][1] * b.x + a[3][2] * b.y + a[3][3] * b.z
		return c
	end

	if type(a) == "table" and a.CLASS == "Matrix3" and 
		type(b) == "table" and b.CLASS == "Matrix3" then
		local c = Matrix3:create()
		for i = 1,3 do
			for j = 1,3 do
				c[i][j] = 0
				for k = 1,3 do
					c[i][j] = c[i][j] + a[i][k] * b[k][j]
				end
			end
		end
		return c
	end

	if type(a) == "number" then
		local c = Matrix3:create(b)
		for i = 1,3 do
			for j = 1,3 do
				c[i][j] = b[i][j] * a
			end
		end
		return c
	end

	if type(b) == "number" then
		local c = Matrix3:create(a)
		for i = 1,3 do
			for j = 1,3 do
				c[i][j] = a[i][j] * b
			end
		end
		return c
	end

	return Matrix3:create()
end

function Matrix3.__eq(a,b)
	local T = true
	for i = 1,3 do
		for j = 1,3 do
			T = T and (a[i][j] == b[i][j])
		end
	end

	return T
end

-- |A|
function Matrix3:det()
	return self:determinant()
end
function Matrix3:determinant()
	local A = 0;
	A = A + self[1][1] * (self[2][2] * self[3][3] - self[2][3] * self[3][2])
	A = A + self[1][2] * (self[2][3] * self[3][1] - self[3][2] * self[2][1])
	A = A + self[1][3] * (self[2][1] * self[3][2] - self[2][2] * self[3][1])
	return A
end
function Matrix3:A()
	return self:determinant()
end

-- to be filled:
-- function reverse
function Matrix3:rev()
	return self:reverse()
end
function Matrix3:reverse()
	if self:determinant() == 0 then
		return self:create()
	else
		return self:adj() * (1/self:determinant())
	end
end
-- function A* adj()
function Matrix3:adj()
	return Matrix3:create(
		 (self[2][2] * self[3][3] - self[2][3] * self[3][2]),
		-(self[2][1] * self[3][3] - self[2][3] * self[3][1]),
		 (self[2][1] * self[3][2] - self[2][2] * self[3][1]),

		-(self[1][2] * self[3][3] - self[1][3] * self[3][2]),
		 (self[1][1] * self[3][3] - self[1][3] * self[3][1]),
		-(self[1][1] * self[3][2] - self[1][2] * self[3][1]),

		 (self[1][2] * self[2][3] - self[1][3] * self[2][2]),
		-(self[1][1] * self[2][3] - self[1][3] * self[2][1]),
		 (self[1][1] * self[2][2] - self[1][2] * self[2][1])
	)
end

function Matrix3:__tostring()
	local str
	str = 		 "[" .. self[1][1] .. " " .. self[1][2] .. " " .. self[1][3] .. " \n"
	str = str .. " " .. self[2][1] .. " " .. self[2][2] .. " " .. self[2][3] .. " \n"
	str = str .. " " .. self[3][1] .. " " .. self[3][2] .. " " .. self[3][3] .. "]"

	return str
end

return Matrix3
