import sys

if __name__ == "__main__":
    numbers = list(map(int, sys.stdin.readline().split(" ")))
    numbers = [num * num for num in numbers]
    print(sum(numbers) % 10)