package main

func IsValidSudoku(board [][]byte) bool {
	rows := make([]map[byte]bool, 9)
	cols := make([]map[byte]bool, 9)
	boxes := make([]map[byte]bool, 9)

	for i := range 9 {
		rows[i] = make(map[byte]bool)
		cols[i] = make(map[byte]bool)
		boxes[i] = make(map[byte]bool)
	}

	for r := range 9 {
		for c := range 9 {
			val := board[r][c]

			if val == '.' {
				continue
			}

			boxIdx := (r/3)*3 + (c / 3)
			if rows[r][val] || cols[c][val] || boxes[boxIdx][val] {
				return false
			}

			rows[r][byte(val)] = true
			cols[c][byte(val)] = true
			boxes[boxIdx][byte(val)] = true
		}
	}

	return true
}
