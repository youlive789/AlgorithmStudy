import sys
from collections import deque

if __name__ == "__main__":
    queue_size, target_count = list(map(int, list(sys.stdin.readline().split(" "))))
    targets = list(map(int, list(sys.stdin.readline().split(" "))))
    
    q = deque(list(map(lambda x: x+1, list(range(queue_size)))))
    q_half = queue_size // 2
    
    rotate_count = 0
    for target in targets:
        while target != q[0]:
            if q_half > abs(target - q[0]):
                if target < q[0]:
                    q.rotate(1)
                    rotate_count += 1
                elif target > q[0]:
                    q.rotate(-1)
                    rotate_count += 1
            else:
                if target > q[0]:
                    q.rotate(1)
                    rotate_count += 1
                elif target < q[0]:
                    q.rotate(-1)
                    rotate_count += 1

        q.popleft()
    
    print(rotate_count)