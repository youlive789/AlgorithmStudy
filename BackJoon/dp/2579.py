import sys

if __name__ == "__main__":
    cases = int(sys.stdin.readline())

    steps = []
    for _ in range(cases):
        steps.append(int(sys.stdin.readline()))

    dp = [0 for _ in range(len(steps))]
    dp[0] = steps[0]
    dp[1] = max(steps[0]+steps[1], steps[1])
    dp[2] = max(steps[0]+steps[2], steps[1]+steps[2])

    trigger = 0
    for idx in range(3, len(steps)):
        dp[idx] = max(dp[idx-3] + steps[idx-1] + steps[idx], dp[idx-2] + steps[idx])

    print(dp[-1])