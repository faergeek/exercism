local BankAccount = {}

--- @class BankAccount
--- @field private _balance number
--- @field private _closed boolean
local BankAccountPrototype = {}
BankAccountPrototype.__index = BankAccountPrototype

function BankAccount:new()
	return setmetatable({ _balance = 0, _closed = false }, BankAccountPrototype)
end

function BankAccountPrototype:balance()
	return self._balance
end

--- @param amount number
function BankAccountPrototype:deposit(amount)
	if self._closed then
		error("Account is closed")
	end

	if amount <= 0 then
		error("Invalid amount")
	end

	self._balance = self._balance + amount
end

--- @param amount number
function BankAccountPrototype:withdraw(amount)
	if self._closed then
		error("Account is closed")
	end

	if amount <= 0 then
		error("Invalid amount")
	end

	if amount > self._balance then
		error("Not enough balance")
	end

	self._balance = self._balance - amount
end

function BankAccountPrototype:close()
	self._closed = true
end

return BankAccount
