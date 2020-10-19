import sys

if __name__ == "__main__":
    # 단어를 입력받는다.
    word_table = []
    word_count = int(sys.stdin.readline())
    for _ in range(word_count):
        word_table.append(sys.stdin.readline().replace("\n", ""))

    # 단어배열을 길이로 정렬한다.
    # 배열을 순회하면서 알파벳에 숫자를 매핑한다.
    # 배열을 순회하면서 매핑된 알파벳에 따라 숫자로 변환한다.

