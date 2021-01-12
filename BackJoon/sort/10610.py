target = list(input())
target.sort(reverse=True)

answer = int("".join(target))
if answer % 30 == 0:
    print(answer)
else:
    print(-1)