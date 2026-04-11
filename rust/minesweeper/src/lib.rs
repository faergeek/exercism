const MINE_CELL: u8 = b'*';

pub fn annotate(minefield: &[&str]) -> Vec<String> {
    let mut result = Vec::with_capacity(minefield.len());

    let rows: Vec<&[u8]> = minefield.iter().map(|row| row.as_bytes()).collect();

    for (i, cells) in rows.iter().enumerate() {
        let mut row = String::new();

        let start_i = if i == 0 { 0 } else { i - 1 };
        let end_i = (i + 1).min(rows.len() - 1);

        for (j, &cell) in cells.iter().enumerate() {
            let mut count = 0;

            if cell != MINE_CELL {
                let start_j = if j == 0 { 0 } else { j - 1 };
                let end_j = (j + 1).min(cells.len() - 1);

                for ii in start_i..=end_i {
                    for jj in start_j..=end_j {
                        if rows[ii][jj] == MINE_CELL {
                            count += 1;
                        }
                    }
                }
            }

            if count == 0 {
                row.push(cell as char);
            } else {
                row.push(count.to_string().as_bytes()[0] as char);
            }
        }

        result.push(row);
    }

    result
}
