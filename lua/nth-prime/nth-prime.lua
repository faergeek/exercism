local function is_prime(n)
	local sqrt = math.sqrt(n)
	local floored_sqrt = math.floor(sqrt)

	if floored_sqrt == sqrt then
		return false
	end

	for i = 2, floored_sqrt do
		if n % i == 0 then
			return false
		end
	end

	return true
end

return function(n)
	if n < 1 then
		error("n must be greater than 0")
	end

	local candidate = 2
	local count = 0

	while count < n do
		if is_prime(candidate) then
			count = count + 1
		end

		candidate = candidate + 1
	end

	return candidate - 1
end
