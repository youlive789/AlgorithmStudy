import sys
import heapq

if __name__ == "__main__":
    h, cmd = [], []
    count = int(sys.stdin.readline())
    for _ in range(count):
        cmd.append(int(sys.stdin.readline()))
        
    for c in cmd:
        if c == 0:
            if not h:
                print(0)
            else:
                print(heapq.heappop(h))
        else:
            heapq.heappush(h, c)

    
