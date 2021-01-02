one, two, three = list(map(int, input().split(" ")))

fee_table = [0 for _ in range(100)]
for _ in range(3):
    start, end = list(map(int, input().split(" ")))
    for idx in range(start-1, end-1):
        fee_table[idx] += 1

answer = 0
for fee in fee_table:
    if fee == 1:
        answer += (fee * one)
    elif fee == 2:
        answer += (fee * two)
    elif fee == 3:
        answer += (fee * three)

print(answer)