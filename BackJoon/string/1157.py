import sys

def get_most_char(s):
    char_dict = {}
    for c in s:
        if c in char_dict:
            char_dict[c] += 1
        else:
            char_dict[c] = 1

    count = 0
    answer = ''
    for char, cnt in char_dict.items():
        if cnt > count:
            answer = char
            count = cnt
    
    double_count = False
    for char, cnt in char_dict.items():
        if not double_count and cnt == count:
            double_count = True
        elif double_count and cnt == count:
            return "?"
    
    return answer


if __name__ == "__main__":
    string = sys.stdin.readline().replace("\n", "")
    print(get_most_char(string.upper()))