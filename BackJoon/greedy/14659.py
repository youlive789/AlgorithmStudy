count = int(input())
height = list(map(int, input().split(" ")))

answer = 0
for idx in range(count):
    kill_count = 0
    idx_now, idx_count = idx + 1, 0
    while idx_count < count - 1 and idx_now < count:
        if height[idx] > height[idx_now]:
            kill_count += 1
        else:
            break
        idx_now += 1
        idx_count += 1

    answer = max(kill_count, answer)

print(answer)