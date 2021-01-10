import sys

if __name__ == "__main__":
    coins = [50000, 10000, 5000, 1000, 500, 100, 50, 10]

    money = int(sys.stdin.readline())

    answer = 0
    for idx in range(len(coins)):
        if money >= coins[idx]:
            answer += (money // coins[idx])
            money %= coins[idx]
        
    print(answer)