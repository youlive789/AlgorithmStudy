import sys

if __name__ == "__main__":
    n, m = list(map(int, sys.stdin.readline().split(" ")))

    names = {}
    for _ in range(n + m):
        name = sys.stdin.readline().replace("\n", "")
        if name not in names:
            names[name] = 1
        else:
            names[name] += 1

    answer = []
    for name, count in names.items():
        if count == 2:
            answer.append(name)

    answer.sort()
    print(len(answer))
    for name in answer:
        print(name)
    