import sys
from collections import deque

if __name__ == "__main__":
    card_count = int(sys.stdin.readline())
    cards = list(map(lambda x: x + 1, list(range(card_count))))
    cards = deque(cards)

    while len(cards) > 1:
        cards.popleft()
        cards.rotate(-1)
    
    print(cards[-1])

