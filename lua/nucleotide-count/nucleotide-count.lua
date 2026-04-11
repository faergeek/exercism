---@alias NucleotideCounts { A: number; C: number; G: number; T: number }

---@class DNA
---@field nucleotideCounts NucleotideCounts
local DNA = {}

---@param input string
function DNA:new(input)
	local nucleotideCounts = { A = 0, C = 0, G = 0, T = 0 }

	for i = 1, input:len() do
		local nucleotide = input:sub(i, i)
		local count = nucleotideCounts[nucleotide]

		if not count then
			error("Invalid Sequence")
		end

		nucleotideCounts[nucleotide] = count + 1
	end

	return setmetatable({ nucleotideCounts = nucleotideCounts }, {
		__index = DNA,
	})
end

---@param nucleotide string
function DNA:count(nucleotide)
	local count = self.nucleotideCounts[nucleotide]

	if not count then
		error("Invalid Nucleotide")
	end

	return count
end

return DNA
