local M = {}

local codon_to_protein = {}

local function add(protein, ...)
  for _, value in ipairs(table.pack(...)) do
    codon_to_protein[value] = protein
  end
end

add('Methionine', 'AUG')
add('Phenylalanine', 'UUU', 'UUC')
add('Leucine', 'UUA', 'UUG')
add('Serine', 'UCU', 'UCC', 'UCA', 'UCG')
add('Tyrosine', 'UAU', 'UAC')
add('Cysteine', 'UGU', 'UGC')
add('Tryptophan', 'UGG')
add('STOP', 'UAA', 'UAG', 'UGA')

function M.codon(codon) return codon_to_protein[codon] or error() end

function M.rna_strand(rna_strand)
  local result = {}

  for i = 1, #rna_strand, 3 do
    local codon = string.sub(rna_strand, i, i + 2)
    local protein = M.codon(codon)
    if protein == 'STOP' then break end

    table.insert(result, protein)
  end

  return result
end

return M
