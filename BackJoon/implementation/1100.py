import sys

if __name__ == "__main__":
    chess_table = []
    for _ in range(8):
        chess_table.append(list(sys.stdin.readline().replace("\n", "")))

    result = 0
    for row in range(8):
        for col in range(8):
            if row % 2 == 0:
                if col % 2 == 0 and chess_table[row][col] == "F":
                    result += 1
            else:
                if col % 2 == 1 and chess_table[row][col] == "F":
                    result += 1
    print(result)