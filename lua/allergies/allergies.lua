local allergens = {
	"eggs",
	"peanuts",
	"shellfish",
	"strawberries",
	"tomatoes",
	"chocolate",
	"pollen",
	"cats",
}

local function list(score)
	local result = {}

	for i, allergen in ipairs(allergens) do
		if score & (2 ^ (i - 1)) ~= 0 then
			table.insert(result, allergen)
		end
	end

	return result
end

local function allergic_to(score, which)
	for i, allergen in ipairs(allergens) do
		if allergen == which and score & (2 ^ (i - 1)) ~= 0 then
			return true
		end
	end

	return false
end

return {
	list = list,
	allergic_to = allergic_to,
}
