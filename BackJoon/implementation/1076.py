import sys

if __name__ == "__main__":
    color = []
    for _ in range(3):
        color.append(sys.stdin.readline().replace("\n", ""))

    table = ["black", "brown", "red", "orange", "yellow",
        "green", "blue", "violet", "grey", "white"]

    answer = ""
    for idx, c in enumerate(color):
        if idx == 2:
            answer = int(answer)
            answer *= 10**table.index(c)
        else:
            answer += str(table.index(c))
        
    print(answer)