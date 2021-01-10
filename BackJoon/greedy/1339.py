import sys
from collections import OrderedDict

if __name__ == "__main__":
    # 단어를 입력받는다.
    word_table = []
    word_count = int(sys.stdin.readline())
    word_max_length, word_min_length = 0, sys.maxsize
    for _ in range(word_count):
        word = sys.stdin.readline().replace("\n", "")
        word_max_length = max(len(word), word_max_length)
        word_min_length = min(len(word), word_min_length)
        word_table.append(word)

    