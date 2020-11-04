import sys

if __name__ == "__main__":
    longer = sys.stdin.readline().replace("\n", "")
    shorter = sys.stdin.readline().replace("\n", "")

    if len(longer) >= len(shorter):
        print("go")
    else:
        print("no")