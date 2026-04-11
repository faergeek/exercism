return function(s)
	local letters = {}

	for l in s:lower():gmatch("%a") do
		if letters[l] then
			return false
		end

		letters[l] = true
	end

	return true
end
