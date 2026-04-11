--- @enum Color
local Color = {
	["black"] = 0,
	["brown"] = 1,
	["red"] = 2,
	["orange"] = 3,
	["yellow"] = 4,
	["green"] = 5,
	["blue"] = 6,
	["violet"] = 7,
	["grey"] = 8,
	["white"] = 9,
}

return {
	--- @param c1 Color
	--- @param c2 Color
	--- @param c3 Color
	--- @return number, 'ohms' | 'kiloohms'
	decode = function(c1, c2, c3)
		local value = (Color[c1] * 10 + Color[c2]) * (10 ^ Color[c3])

		if value > 1000 then
			return value / 1000, "kiloohms"
		else
			return value, "ohms"
		end
	end,
}
