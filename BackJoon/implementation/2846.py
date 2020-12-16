count = int(input())
height = list(map(int, input().split(" ")))

answer = 0
idx_now, idx_last, idx_height = 0, 0, 0
while idx_now < count:
    if height[idx_now] > height[idx_height]:
        answer = max(answer, height[idx_now] - height[idx_height])

    if height[idx_now] <= height[idx_height]:
        idx_height = idx_now

    if height[idx_now] <= height[idx_last]:
        idx_height = idx_now

    idx_now += 1
    idx_last = idx_now - 1

print(answer)