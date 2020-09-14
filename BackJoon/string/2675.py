import sys

def repeat(s, number):
    result = ""
    for char in s:
        for _ in range(number):
            result += char
    return result

if __name__ == "__main__":
    count = int(sys.stdin.readline())
    while count > 0:
        t = sys.stdin.readline().replace("\n", "").split(" ")
        number = int(t[0])
        string = t[1]

        print(repeat(string, number))
        count -= 1