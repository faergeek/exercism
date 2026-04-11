return {
	encode = function(s)
		local result = ""

		local len = #s
		local i = 1

		while i <= len do
			local char = s:sub(i, i)
			i = i + 1

			local repeats = 1
			while s:sub(i, i) == char do
				repeats = repeats + 1
				i = i + 1
			end

			if repeats > 1 then
				result = result .. repeats
			end

			result = result .. char
		end

		return result
	end,

	decode = function(s)
		local result = ""

		local len = #s
		local i = 1

		while i <= len do
			local char = s:sub(i, i)
			local digit = tonumber(char)
			local repeats

			if digit then
				repeats = 0
				repeat
					repeats = repeats * 10 + digit
					i = i + 1
					char = s:sub(i, i)
					digit = tonumber(char)
				until not digit
			else
				repeats = 1
			end

			result = result .. string.rep(char, repeats)
			i = i + 1
		end

		return result
	end,
}
