from collections import deque

q_size, pop_count = list(map(int, input().split(" ")))
pop_target = list(map(int, input().split(" ")))

q = deque([i for i in range(1, q_size+1)])

answer = 0
for target in pop_target:
    target_position = q.index(target)
    q_half = len(q) // 2
    
    if target_position > q_half:
        trigger = 1
    else:
        trigger = -1

    while q[0] != target:
        q.rotate(trigger)
        answer += 1

    q.popleft()
     
print(answer)