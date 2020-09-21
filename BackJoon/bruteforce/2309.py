import sys

if __name__ == "__main__":
    heights = []
    for _ in range(9):
        heights.append(int(sys.stdin.readline()))

    heights.sort()
    checker = sum(heights) - 100

    not_dwarf = []
    for idx, item in enumerate(heights):
        try:
            check = heights.index(checker - item)
            if check > -1 :
                not_dwarf.append(item)
                not_dwarf.append(heights[check])
                break
        except:
            pass

    for i in heights:
        if i not in not_dwarf:
            print(i)

