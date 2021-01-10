import sys

if __name__ == "__main__":
    hour, minute, second = list(map(int, sys.stdin.readline().split(" ")))
    last = int(sys.stdin.readline())

    second += last
    minute += second // 60
    second %= 60
    hour += minute // 60
    minute %= 60
    
    if hour > 23:
        hour %= 24

    print(hour, minute, second)