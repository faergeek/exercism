local function reduce(xs, value, f)
	local acc = value

	for _, x in ipairs(xs) do
		acc = f(x, acc)
	end

	return acc
end

local function map(xs, f)
	return reduce(xs, {}, function(x, acc)
		table.insert(acc, f(x))
		return acc
	end)
end

local function filter(xs, pred)
	return reduce(xs, {}, function(x, acc)
		if pred(x) then
			table.insert(acc, x)
		end

		return acc
	end)
end

return {
	map = map,
	reduce = reduce,
	filter = filter,
}
