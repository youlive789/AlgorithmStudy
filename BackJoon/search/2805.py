import time
import sys

wood_count, target_length = list(map(int, input().split(" ")))
woods = list(map(int, input().split(" ")))
wood_max = max(woods)

low, high, height = 0, wood_max, 0
while low <= high:

    mid = (low + high) // 2
    sum_current = 0
    for wood in woods:
        if wood > mid:
            sum_current += (wood - mid)

    if sum_current >= target_length:
        low = mid + 1
    else:
        high = mid - 1

print(high)