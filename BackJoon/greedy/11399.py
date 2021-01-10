import sys

if __name__ == "__main__":
    count = int(sys.stdin.readline())
    line = list(map(int, sys.stdin.readline().split(" ")))

    line.sort()
    summation = [0 for _ in range(count)]
    for idx in range(count):
        if idx == 0:
            summation[idx] = line[idx]
        else:
            summation[idx] = summation[idx-1] + line[idx]


    print(sum(summation))