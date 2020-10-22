import sys

if __name__ == "__main__":
    number, a, b = list(map(int, sys.stdin.readline().split(" ")))
    a -= 1
    b -= 1

    rounds = {}
    num_rounds = 1
    for idx in range(number):
        if idx == a or idx == b:
            rounds[idx] = True
        else:
            rounds[idx] = False

    while number >= 1:
        next_rounds = {}
        last, idx_next = 0, 0
        for idx in range(1, number, 2):
            if rounds[last] and rounds[idx]:
                print(num_rounds)
                break
            elif rounds[last] or rounds[idx]:
                next_rounds[idx_next] = True
            else:
                next_rounds[idx_next] = False
            last += 2
            idx_next += 1

        if number % 2 == 1:
            if rounds[number - 1]:
                next_rounds[idx_next] = True
            else:
                next_rounds[idx_next] = False

        number = len(next_rounds)
        rounds = next_rounds
        num_rounds += 1