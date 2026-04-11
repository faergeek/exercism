return function(s)
	local rows = {}

	for line in s:gmatch("([^\n]*)\n?") do
		local row = {}

		for digit in line:gmatch("(%d+)%s*") do
			table.insert(row, tonumber(digit, 10))
		end

		table.insert(rows, row)
	end

	return {
		row = function(n)
			return rows[n]
		end,
		column = function(n)
			local col = {}

			for i = 1, #rows do
				table.insert(col, rows[i][n])
			end

			return col
		end,
	}
end
