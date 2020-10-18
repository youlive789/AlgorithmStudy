import sys

if __name__ == "__main__":
    
    strings = []
    max_string_length = 0

    for _ in range(5):
        inputs = sys.stdin.readline().replace("\n", "")
        max_string_length = max(max_string_length, len(inputs))
        strings.append(inputs)

    answer = ""
    for idx in range(max_string_length):
        for string in strings:
            if len(string) <= idx:
                continue
            else:
                answer += string[idx]

    print(answer)
    