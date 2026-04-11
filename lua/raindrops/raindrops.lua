return function(n)
  local result = {}

  if n % 3 == 0 then table.insert(result, 'Pling') end
  if n % 5 == 0 then table.insert(result, 'Plang') end
  if n % 7 == 0 then table.insert(result, 'Plong') end

  if #result == 0 then return tostring(n) end

  return table.concat(result, '')
end
