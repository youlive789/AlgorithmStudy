count = int(input())
num_list = list(set(map(int, input().split(" "))))
num_list.sort()
print(*num_list)
