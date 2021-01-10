count = int(input())

scores = []
for _ in range(count):
    scores.append(int(input()))
    
answer = 0
for idx in range(count-1, 0, -1):
    while scores[idx] <= scores[idx-1]:
        scores[idx-1] -= 1
        answer += 1

print(answer)

