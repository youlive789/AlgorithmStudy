import sys

if __name__ == "__main__":
    cnt = 0
    size = int(sys.stdin.readline())
    
    half = size // 2
    for b in range(half, 0, -1):
        for c in range(b, 0, -1):
            shortest = size - b - c
            if 0 < shortest <= c:
                cnt += 1
            else:
                break
            
    print(cnt)
