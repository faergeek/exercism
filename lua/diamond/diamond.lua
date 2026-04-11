return function(which)
	if #which ~= 1 or which < "A" or which > "Z" then
		error(string.format("Invalid input: %s", which))
	end

	local start_byte = string.byte("A", 1, 1)
	local end_byte = string.byte(which, 1, 1)
	local end_index = end_byte - start_byte

	local side_length = end_index * 2 + 1
	local result = {}
	for i = 0, end_byte - start_byte do
		local padding_size = end_index - i
		local middle_size = side_length - padding_size * 2
		local letter = string.char(start_byte + i)

		local middle
		if middle_size == 1 then
			middle = letter
		else
			middle = letter .. string.rep(" ", middle_size - 2) .. string.char(start_byte + i)
		end

		local padding = string.rep(" ", padding_size)
		table.insert(result, padding .. middle .. padding)
	end

	for i = #result - 1, 1, -1 do
		table.insert(result, result[i])
	end

	return table.concat(result, "\n") .. "\n"
end
