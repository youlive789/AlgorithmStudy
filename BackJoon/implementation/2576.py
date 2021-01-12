import sys

if __name__ == "__main__":
    num_table = []
    for _ in range(7):
        num_table.append(int(sys.stdin.readline()))

    num_table.sort()

    odd_sum = 0
    odd_min = sys.maxsize
    for num in num_table:
        if num % 2 == 1:
            odd_sum += num
            odd_min = min(odd_min, num)

    if odd_sum == 0:
        print(-1)
    else:
        print(odd_sum)
        print(odd_min)