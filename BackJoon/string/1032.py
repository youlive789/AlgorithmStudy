import sys

if __name__ == "__main__":
    count_strings = int(sys.stdin.readline())

    list_strings = []
    for _ in range(count_strings):
        list_strings.append(sys.stdin.readline().replace("\n", ""))

    # 문자열 길이만큼의 배열생성
    pattern = [""] * len(list_strings[0])
    
    # 입력받은 문자열들을 순회
    for idx_char in range(len(list_strings[0])):
        char_check = True
        last = list_strings[0][idx_char]
        for idx_string in range(1, count_strings):
            if list_strings[idx_string][idx_char] != last:
                char_check = False

        if char_check:
            pattern[idx_char] = list_strings[0][idx_char]
        else:
            pattern[idx_char] = "?"
                
    print("".join(pattern))