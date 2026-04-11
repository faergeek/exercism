local function to_decimal(input)
	local result = 0

	if not input:match("^([01]+)$") then
		return result
	end

	local reversed = input:reverse()
	for i = 1, #reversed do
		local n = tonumber(reversed:sub(i, i))

		result = result + 2 ^ (i - 1) * n
	end

	return result
end

return {
	to_decimal = to_decimal,
}
