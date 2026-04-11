return function(s)
	local letters = {}

	for letter in string.gmatch(s, "%a") do
		local lowercase_letter = string.lower(letter)

		if letters[lowercase_letter] then
			return false
		end

		letters[lowercase_letter] = true
	end

	return true
end
