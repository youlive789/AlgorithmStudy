import sys

color_paper = [
    [1, 1],
    [2, 2],
    [3, 3],
    [4, 4],
    [5, 5]
]
MAX_VAL = 999999

# 해당 색종이로 덮을 수 있는지 체크한다.
def can_cover(row, col, now_color_paper, table):
    pass

# 색종이로 덮을 수 있는 최소 개수를 센다.
def count_cover(cnt, row, col, table):
    pass


if __name__ == "__main__":
    table = []
    for row in range(10):
        table.append(list(map(int, sys.stdin.readline().split(" "))))

    result = count_cover(0, 0, 0, table)
    print(result)