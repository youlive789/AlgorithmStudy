import sys

if __name__ == "__main__":
    num_rope = int(sys.stdin.readline())

    ropes = []
    for _ in range(num_rope):
        ropes.append(int(sys.stdin.readline()))

    ropes.sort()

    weight = 0
    for idx in range(0, num_rope):
        weight_new = (num_rope - idx) * ropes[idx]
        if weight_new > weight:
            weight = weight_new

    print(weight)
