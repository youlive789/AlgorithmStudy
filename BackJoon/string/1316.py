import sys

def check_group(string):
    last = ""
    last_str = set()
    for c in string:
        if c in last_str and last != c:
            return False
        last_str.add(c)
        last = c
    return True


if __name__ == "__main__":
    case = int(sys.stdin.readline())

    result = 0
    for _ in range(case):
        now_string = sys.stdin.readline()
        if check_group(now_string):
            result += 1

    print(result)