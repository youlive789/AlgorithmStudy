import sys

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    A = list(map(int, sys.stdin.readline().replace("\n", "").split(" ")))
    B = list(map(int, sys.stdin.readline().replace("\n", "").split(" ")))

    A_sorted = sorted(A)
    B_sorted = sorted(B, reverse=True)
    
    answer = 0
    for idx in range(size):
        answer += A_sorted[idx] * B_sorted[idx]

    print(answer)
        