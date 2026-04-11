--- @class Set
--- @field private _items number[]
local Set = {}
Set.__index = Set

--- @param ... number
--- @return Set
function Set.new(...)
	local instance = setmetatable({ _items = {} }, Set)

	for _, n in ipairs({ ... }) do
		instance:add(n)
	end

	return instance
end

--- @param n number
function Set:add(n)
	if not self:contains(n) then
		table.insert(self._items, n)
	end
end

function Set:is_empty()
	return #self._items == 0
end

--- @param n number
function Set:contains(n)
	for _, value in ipairs(self._items) do
		if value == n then
			return true
		end
	end

	return false
end

--- @param another Set
function Set:is_subset(another)
	for _, value in ipairs(self._items) do
		if not another:contains(value) then
			return false
		end
	end

	return true
end

--- @param another Set
function Set:is_disjoint(another)
	for _, value in ipairs(self._items) do
		if another:contains(value) then
			return false
		end
	end

	return true
end

--- @param another Set
function Set:equals(another)
	return #another._items == #self._items and self:is_subset(another)
end

--- @param another Set
function Set:intersection(another)
	local result = Set.new()

	for _, n in ipairs(self._items) do
		if another:contains(n) then
			result:add(n)
		end
	end

	return result
end

--- @param another Set
function Set:difference(another)
	local result = Set.new()

	for _, n in ipairs(self._items) do
		if not another:contains(n) then
			result:add(n)
		end
	end

	return result
end

--- @param another Set
function Set:union(another)
	local result = Set.new()

	for _, n in ipairs(self._items) do
		result:add(n)
	end

	for _, n in ipairs(another._items) do
		result:add(n)
	end

	return result
end

--- @param ... number
return function(...)
	return Set.new(...)
end
