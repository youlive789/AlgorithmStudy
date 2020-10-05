import sys

def fibo(n):
    if n <= 1:
        return n

    dp = [0] * (n + 1)
    dp[0] = 0
    dp[1] = 1
    for idx in range(2, n + 1):
        dp[idx] = dp[idx - 1] + dp[idx - 2]
    return dp[n]


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    print(fibo(n))