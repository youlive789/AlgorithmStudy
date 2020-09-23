import sys

def get_result(num):
    if num == 3:
        print("A")
    elif num == 2:
        print("B")
    elif num == 1:
        print("C")
    elif num == 0:
        print("D")
    else:
        print("E")

if __name__ == "__main__":
    lines = []
    for _ in range(3):
        line = sum(list(map(int, sys.stdin.readline().replace("\n", "").split(" "))))
        lines.append(line)

    for line in lines:
        get_result(line)
