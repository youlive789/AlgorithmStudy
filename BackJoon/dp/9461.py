import sys

if __name__ == "__main__":
    test_case = int(sys.stdin.readline())
    for _ in range(test_case):
        number = int(sys.stdin.readline())
        if number < 4:
            print(1)
            continue

        cache = [0 for _ in range(101)]
        for idx in range(4):
            cache[idx] = 1

        for idx in range(4, number+1):
            cache[idx] = cache[idx-2] + cache[idx-3]

        print(cache[number])

"""
1 2 3 4 5 6 7 8 9 10 11
1 1 1 2 2 3 4 5 7 9 12

P(N) = P(N-2) + P(N-3)
"""
