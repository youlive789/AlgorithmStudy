import sys

"""

F(N) = max(F(N-3) + d(N-1) + d(N), F(N-2) + d(N))

"""

if __name__ == "__main__":
    count = int(sys.stdin.readline())
    wine_table = []
    for _ in range(count):
        wine_table.append(int(sys.stdin.readline()))

    if count == 1:
        print(wine_table[0])
        exit()
    elif count == 2:
        print(max(wine_table[0]+wine_table[1], wine_table[1]))
        exit()

    dp = [0 for _ in range(count)]
    dp[0] = wine_table[0]
    dp[1] = max(wine_table[0]+wine_table[1], wine_table[1])
    dp[2] = max(wine_table[0]+wine_table[2], wine_table[1]+wine_table[2], dp[1])

    trigger = 0
    for idx in range(3, count):
        dp[idx] = max(dp[idx-3] + wine_table[idx-1] + wine_table[idx], dp[idx-2] + wine_table[idx])
        dp[idx] = max(dp[idx], dp[idx-1])

    print(dp[-1])
    