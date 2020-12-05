import sys

if __name__ == "__main__":
    idx_case = 0
    while True:
        idx_case += 1
        days = list(map(int, sys.stdin.readline().split(" ")))
        if [0,0,0] == days:
            break

        L, P, V = days

        answer = (V // P) * L
        mod = V % P

        if mod < L:
            answer += mod
        else:
            answer += L

        answer_string = "Case {idx}: {answer}".format(idx=idx_case, answer=answer)
        print(answer_string)