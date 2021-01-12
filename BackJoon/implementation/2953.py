import sys

if __name__ == "__main__":
    sums = []
    for _ in range(5):
        sums.append(sum(list(map(int, sys.stdin.readline().split(" ")))))

    answer = max(sums)
    idx_answer = sums.index(answer)
    print(idx_answer + 1, answer)