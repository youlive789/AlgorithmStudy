import sys

if __name__ == "__main__":
    cases = int(sys.stdin.readline())
    weight = list(map(int, sys.stdin.readline().split(" ")))

    weight.sort(reverse=True)

    num_check = 1
    while True:
        target = num_check
        for idx in range(cases):
            if weight[idx] == target:
                target -= weight[idx]
                num_check += weight[idx]
                break
            elif weight[idx] < target:
                target -= weight[idx]

        if target > 0:
            break

    print(num_check)
