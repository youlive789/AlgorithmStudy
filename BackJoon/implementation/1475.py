import sys

def num_table_empty(num_table):
    for _, cnt in num_table.items():
        if cnt >= 1:
            return False
    return True

if __name__ == "__main__":
    target = list(sys.stdin.readline().replace("\n", ""))
    target = list(map(int, target))

    num_table = {}
    for i in range(10):
        num_table[i] = 0

    for num in target:
        if num in num_table:
            num_table[num] += 1

    cnt = 0
    while not num_table_empty(num_table):
        cnt_table = [1] * 10
        for num in num_table:
            if cnt_table[num] == 1:
                num_table[num] -= 1
                cnt_table[num] -= 1

            if cnt_table[6] == 1 and num_table[9] >= 1:
                num_table[9] -= 1
                cnt_table[6] -= 1

            if cnt_table[9] == 1 and num_table[6] >= 1:
                num_table[6] -= 1
                cnt_table[9] -= 1
        cnt += 1

    print(cnt)