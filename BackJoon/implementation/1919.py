import sys
from collections import Counter

if __name__ == "__main__":
    first = sys.stdin.readline().replace("\n", "")
    second = sys.stdin.readline().replace("\n", "")

    first_counter = Counter(first)
    second_counter = Counter(second)

    answer_counter = first_counter + second_counter - (first_counter & second_counter) - (first_counter & second_counter)

    answer = 0
    for v, i in answer_counter.items():
        answer += i

    print(answer)