import sys


if __name__ == "__main__":
    row_size, col_size = list(map(int, sys.stdin.readline().split(" ")))

    if row_size == 1:
        print(1)
    elif row_size == 2:
        print(min(4, (col_size + 1) // 2))
    elif row_size >= 3 and col_size < 7:
        print(min(4, col_size))
    else:
        print(col_size - 2)
    

