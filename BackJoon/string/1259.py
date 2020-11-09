import sys

if __name__ == "__main__":
    while True:
        test = sys.stdin.readline().replace("\n", "")
        if test == "0":
            break

        if test == test[::-1]:
            print("yes")
        else:
            print("no")