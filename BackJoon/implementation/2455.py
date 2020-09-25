import sys

if __name__ == "__main__":
    in_person, out_person = [], []
    for i in range(4):
        out_, in_ = list(map(int, sys.stdin.readline().split(" ")))
        out_person.append(out_)
        in_person.append(in_)

    
    answer, result = 0, 0
    for i in range(4):
        result += in_person[i]
        result -= out_person[i]
        if result > answer:
            answer = result

    print(answer)
