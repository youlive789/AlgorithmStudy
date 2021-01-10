import sys

if __name__ == "__main__":
    full_table = set([number for number in range(1, 31)])
    target_table = set()
    for _ in range(28):
        target_table.add(int(sys.stdin.readline()))

    answer = list(full_table - target_table)
    for num in answer:
        print(num)
