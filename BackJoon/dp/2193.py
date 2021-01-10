length = int(input())

if length <= 2:
    print(1)
    exit()

dp = [0 for _ in range(length + 1)]
dp[1] = 1
dp[2] = 1
for idx in range(3, length+1):
    dp[idx] = dp[idx-1] + dp[idx-2]

print(dp[length])