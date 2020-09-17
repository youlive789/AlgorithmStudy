import sys

if __name__ == "__main__":
    table = []
    cnt = int(sys.stdin.readline())

    for _ in range(cnt):
        weight, height = list(map(int, sys.stdin.readline().split(" ")))
        table.append([weight, height])

    rank = [1] * cnt
    for i in range(cnt-1):
        for j in range(i, cnt):
            if table[i][0] > table[j][0] and table[i][1] > table[j][1]:
                rank[j] += 1
            elif table[i][0] < table[j][0] and table[i][1] < table[j][1]:
                rank[i] += 1

    for i in rank:
        print(i, end=" ")
    
    