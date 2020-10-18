import sys

if __name__ == "__main__":
    # 단어를 입력받는다.
    word_table = []
    word_count = int(sys.stdin.readline())
    for _ in range(word_count):
        word_table.append(sys.stdin.readline().replace("\n", ""))

    # 단어배열을 길이로 정렬한다.
    word_table = sorted(word_table, key=lambda x : len(x), reverse=True)

    # 배열을 순회하면서 알파벳에 숫자를 매핑한다.
    char_map = {}
    num_map = 9
    min_length = len(word_table[-1])

    for word in word_table:
        if len(word) > min_length:
            for idx in range(len(word) - min_length):
                if idx < len(word) and num_map >= 0 and word[idx] not in char_map:
                    char_map[word[idx]] = num_map
                    num_map -= 1

    for idx in range(len(word_table[0])):
        for word in word_table:
            if idx < len(word) and num_map >= 0 and word[idx] not in char_map:
                char_map[word[idx]] = num_map
                num_map -= 1

    # 배열을 순회하면서 매핑된 알파벳에 따라 숫자로 변환한다.
    sums = 0
    for word in word_table:
        num_string = ""
        for char in word:
            num_string += str(char_map[char])
        print(num_string)
        sums += int(num_string)
    print(sums)
