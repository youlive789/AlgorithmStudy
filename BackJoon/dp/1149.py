import sys
import copy
sys.setrecursionlimit(10**6)

def paint(idx, last_color, rgb, cache):
    if idx == len(rgb):
        return 0

    if cache[idx][last_color] != -1:
        return cache[idx][last_color]

    result = sys.maxsize
    for idx_color, color in enumerate(rgb[idx]):
        if idx_color != last_color:
            result = min(result, paint(idx + 1, idx_color, rgb, cache) + color)

    cache[idx][last_color] = result
    return cache[idx][last_color]

if __name__ == "__main__":
    house_number = int(sys.stdin.readline())

    rgb = []
    for _ in range(house_number):
        rgb.append(list(map(int, sys.stdin.readline().split(" "))))

    cache = [[-1, -1, -1] for _ in range(len(rgb))]
    print(paint(0, -1, rgb, cache))    
