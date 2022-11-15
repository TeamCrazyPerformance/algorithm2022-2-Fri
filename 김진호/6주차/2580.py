sudoku = [list(map(int, input().split())) for _ in range(9)]
blanks = [(i, j) for i in range(9) for j in range(9) if sudoku[i][j] == 0]


def is_possible(row, col, num):
    for i in range(9):
        if sudoku[i][col] == num:
            return False
    if num in sudoku[row]:
        return False
    for i in range(3):
        for j in range(3):
            if sudoku[row // 3 * 3 + i][col // 3 * 3 + j] == num:
                return False
    return True


def rec(depth):
    if depth == len(blanks):
        for row in sudoku:
            print(*row)
        exit(0)

    row, col = blanks[depth]
    for num in range(1, 10):
        if not is_possible(row, col, num):
            continue
        sudoku[row][col] = num
        rec(depth + 1)
    sudoku[row][col] = 0


rec(0)