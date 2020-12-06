import sys

if __name__ == "__main__":
    num_coin, target = list(map(int, sys.stdin.readline().split(" ")))

    coins = []
    for _ in range(num_coin):
        coins.append(int(sys.stdin.readline()))

    answer = 0
    for idx in range(num_coin-1, -1, -1):
        if target > 0 and coins[idx] <= target:
            answer += target // coins[idx]
            target %= coins[idx]

    print(answer)