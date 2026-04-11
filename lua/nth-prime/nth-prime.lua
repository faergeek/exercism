return function(n)
	if n < 1 then
		error("n must be greater than 0")
	end

	local result = { 2, 3 }

	local candidate = 3
	while #result < n do
		candidate = candidate + 2

		for i = 1, #result do
			if candidate % result[i] == 0 then
				goto continue
			end
		end

		table.insert(result, candidate)

		::continue::
	end

	return result[n]
end
