import sys
from itertools import combinations

if __name__ == "__main__":
    word_size, _ = list(map(int, sys.stdin.readline().split(" ")))
    words = sys.stdin.readline().replace("\n", "").split(" ")
    words.sort()

    aeiou_char = set(["a", "e", "i", "o", "u"])
    other_char = set([chr(i) for i in range(97, 123)]) - aeiou_char

    for comb in combinations(words, word_size):
        if len(set(comb) - aeiou_char) == len(comb):
            continue

        if len(set(comb) - other_char) > len(comb) - 2:
            continue

        print("".join(comb))
