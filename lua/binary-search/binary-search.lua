return function(array, target)
	local l = 1
	local h = #array

	while l <= h do
		local m = l + math.floor((h - l) / 2)
		local item = array[m]

		if item == target then
			return m
		end

		if item < target then
			l = m + 1
		else
			h = m - 1
		end
	end

	return -1
end
