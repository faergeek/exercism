package proteintranslation

import "errors"

var (
	ErrStop        = errors.New("ErrStop")
	ErrInvalidBase = errors.New("ErrInvalidBase")
)

func FromRNA(rna string) ([]string, error) {
	result := make([]string, 0, len(rna)/3)
	for i := 0; i < len(rna); i += 3 {
		if i > len(rna)-2 {
			return nil, ErrInvalidBase
		}

		acid, err := FromCodon(rna[i : i+3])
		if err != nil {
			if errors.Is(err, ErrStop) {
				return result, nil
			}

			return nil, err
		}

		result = append(result, acid)
	}

	return result, nil
}

func FromCodon(codon string) (string, error) {
	switch codon {
	case "AUG":
		return "Methionine", nil
	case "UUU", "UUC":
		return "Phenylalanine", nil
	case "UUA", "UUG":
		return "Leucine", nil
	case "UCU", "UCC", "UCA", "UCG":
		return "Serine", nil
	case "UAU", "UAC":
		return "Tyrosine", nil
	case "UGU", "UGC":
		return "Cysteine", nil
	case "UGG":
		return "Tryptophan", nil
	case "UAA", "UAG", "UGA":
		return "", ErrStop
	default:
		return "", ErrInvalidBase
	}
}
