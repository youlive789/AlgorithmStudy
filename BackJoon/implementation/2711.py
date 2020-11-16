import sys

if __name__ == "__main__":
    count = int(sys.stdin.readline())
    strings = []
    for _ in range(count):
        position, word = sys.stdin.readline().replace("\n", "").split(" ")
        position = int(position)
        word = word[:position - 1] + word[position:]
        strings.append(word)

    for string in strings:
        print(string)