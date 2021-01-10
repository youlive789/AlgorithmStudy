import sys

if __name__ == "__main__":
    count = int(sys.stdin.readline())
    numbers = list(map(int, sys.stdin.readline().split(" ")))

    dp = list(range(count))
    dp[0] = numbers[0]

    for idx in range(1, count):
        dp[idx] = max(numbers[idx], dp[idx-1] + numbers[idx])

    print(max(dp))