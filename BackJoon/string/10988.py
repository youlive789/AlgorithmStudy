import sys

if __name__ == "__main__":
    string = sys.stdin.readline().replace("\n", "")
    if string == string[::-1]:
        print(1)
    else:
        print(0)