import sys

# 해당 색종이로 덮을 수 있는지 체크한다.
def can_cover():
    pass

# 색종이로 덮을 수 있는 최소 개수를 센다.
def count_cover():
    pass

if __name__ == "__main__":
    table = []
    for row in range(10):
        table.append(list(map(int, sys.stdin.readline().split(" "))))