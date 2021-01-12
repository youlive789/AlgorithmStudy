import sys

if __name__ == "__main__":
    row_size, col_size = list(map(int, sys.stdin.readline().split(" ")))

    table = []
    for _ in range(row_size):
        table.append(list(map(int, sys.stdin.readline().split(" "))))

    positions = []
    cases = int(sys.stdin.readline())
    for _ in range(cases):
        positions.append(list(map(int, sys.stdin.readline().split(" "))))

    answer = []
    for idx in range(cases):
        row_start, col_start = positions[idx][0] - 1, positions[idx][1] - 1
        row_end, col_end = positions[idx][2] - 1, positions[idx][3] - 1

        sums = 0
        for row in range(row_size):
            for col in range(col_size):
                if row_start <= row <= row_end and col_start <= col <= col_end:
                    sums += table[row][col]
        answer.append(sums)

    for a in answer:
        print(a)
