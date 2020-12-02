import sys

if __name__ == "__main__":
    num_multitab = int(sys.stdin.readline())

    multitabs = []
    for _ in range(num_multitab):
        multitabs.append(int(sys.stdin.readline()))

    multitabs.sort(reverse=True)

    for idx in range(num_multitab):
        if idx > 0:
            multitabs[idx] -= 1

    print(sum(multitabs))