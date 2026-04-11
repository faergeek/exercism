local ArmstrongNumbers = {}

function ArmstrongNumbers.is_armstrong_number(number)
  local digits = {}
  local n = number
  while n > 0 do
    table.insert(digits, 1, n % 10)
    n = math.floor(n / 10)
  end

  for _, digit in ipairs(digits) do
    n = math.floor(n + digit ^ #digits)
  end

  return n == number
end

return ArmstrongNumbers
