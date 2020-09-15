import sys

cards = None
result = 999999

def blackjack(cnt, cards, target, sums):
    global result
    if cnt == 3:
        if abs(target - sums) < abs(target - result) and target - sums >= 0:
            result = sums
        return

    for idx in range(len(cards)):
        blackjack(cnt + 1, cards[idx+1:], target, sums + cards[idx])

if __name__ == "__main__":
    _, target = list(map(int, sys.stdin.readline().split(" ")))
    cards = list(map(int, sys.stdin.readline().split(" ")))
    
    blackjack(0, cards, target, 0)
    print(result)