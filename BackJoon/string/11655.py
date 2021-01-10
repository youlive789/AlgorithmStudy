import sys

if __name__ == "__main__":
    target = sys.stdin.readline().replace("\n", "")
    target = list(target)

    for idx in range(len(target)):
        if target[idx] != " ":
            char_num = ord(target[idx])

            if 65 <= char_num <= 90:
                char_num += 13
                if char_num > 90:
                    char_num = 65 + (char_num - 91)
            elif 97 <= char_num <= 122:
                char_num += 13
                if char_num > 122:
                    char_num = 97 + (char_num - 123)

            target[idx] = chr(char_num)

    print("".join(target))

    