local leap_year = function(n)
	return n % 4 == 0 and not (n % 100 == 0) or n % 400 == 0
end

return leap_year
