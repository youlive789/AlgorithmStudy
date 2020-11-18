import sys

if __name__ == "__main__":
    name_table = []
    for _ in range(5):
        name_table.append(sys.stdin.readline().replace("\n", ""))

    fbi_table = []
    for idx, name in enumerate(name_table):
        if name.find("FBI") > -1:
            fbi_table.append(idx + 1)

    if not fbi_table:
        print("HE GOT AWAY!")
        exit()

    for fbi in fbi_table:
        print(fbi, end=" ")