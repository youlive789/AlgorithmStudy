import sys
sys.setrecursionlimit(10**6)

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    numbers = list(map(int, sys.stdin.readline().split(" ")))

    answer = 0
    dp = [0 for _ in range(size)]
    for i in range(size):
        now = 0
        for j in range(i + 1):
            if numbers[i] > numbers[j]:
                now = max(now, dp[j])
        dp[i] = now + 1
        answer = max(answer, dp[i])
    print(answer)