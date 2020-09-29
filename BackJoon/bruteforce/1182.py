import sys

def find(idx, target, nums, cnt):
    if idx == len(nums):
        if target == 0 and cnt > 0:
            return 1
        else:
            return 0

    return find(idx + 1, target - nums[idx], nums, cnt + 1) + find(idx + 1, target, nums, cnt)

if __name__ == "__main__":
    _, target = list(map(int, sys.stdin.readline().split(" ")))
    nums = list(map(int, sys.stdin.readline().split(" ")))

    print(find(0, target, nums, 0))