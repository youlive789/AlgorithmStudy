import sys

if __name__ == "__main__":
    count = int(sys.stdin.readline())

    first_names = {}
    for _ in range(count):
        name = sys.stdin.readline().replace("\n", "")
        if name[0] not in first_names:
            first_names[name[0]] = 1
        else:
            first_names[name[0]] += 1

    answer = ""
    for first_name, count in sorted(first_names.items()):
        if count >= 5:
            answer += first_name

    if answer == "":
        print("PREDAJA")
    else:
        print(answer)