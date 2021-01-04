count = int(input())
table = list(map(int, input().split(" ")))

score, last = [], 0
for idx in range(count):
    if last != 0 and table[idx] != 0:
        now_score = last + 1
    else:
        now_score = table[idx]
    score.append(now_score)
    last = now_score

print(sum(score))