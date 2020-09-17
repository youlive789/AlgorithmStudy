import sys

def check_chess_board(board, checker):
    pass

if __name__ == "__main__":
    row, col = list(map(int, sys.stdin.readline().split(" ")))

    board = []
    for _ in range(row):
        board.append(list(sys.stdin.readline().replace("\n", "")))
