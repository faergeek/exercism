local Robot = {}

local RobotProto = {}
RobotProto.__index = RobotProto

local function random_char()
	return string.char(math.random(string.byte("A"), string.byte("Z")))
end

local function random_digit()
	return string.char(math.random(string.byte("0"), string.byte("9")))
end

local used_names = {}
local function generate_name()
	local name

	repeat
		name = table.concat({
			random_char(),
			random_char(),
			random_digit(),
			random_digit(),
			random_digit(),
		}, "")
	until not used_names[name]

	used_names[name] = true

	return name
end

function Robot:new()
	return setmetatable({
		name = generate_name(),
	}, RobotProto)
end

function RobotProto:reset()
	self.name = generate_name()
end

return Robot
