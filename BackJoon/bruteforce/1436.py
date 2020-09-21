import sys

if __name__ == "__main__":
    target = int(sys.stdin.readline())

    index = 0
    result = 0
    for i in range(999999999):
        if "666" in str(i) :
            index += 1

        if index == target:
            result = i
            break

    print(result)

