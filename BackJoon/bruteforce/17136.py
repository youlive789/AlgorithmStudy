import sys

MAX_VAL = 999999

table = []
answer = MAX_VAL
color_paper = [5, 4, 3, 2, 1]

# 해당 색종이로 덮을 수 있는지 체크한다.
def can_cover(row, col, now_color_paper):
    row_target = row + color_paper[now_color_paper]
    col_target = col + color_paper[now_color_paper]

    for row_check in range(row, row_target+1):
        for col_check in range(col, col_target+1):
            if table[row_check][col_check] != 1:
                return False
    return True

# 색종이로 덮거나 뗀다.
def cover(row, col, now_color_paper, is_cover):
    row_target = row + color_paper[now_color_paper]
    col_target = col + color_paper[now_color_paper]

    for row_check in range(row, row_target+1):
        for col_check in range(col, col_target+1):
            if is_cover:
                table[row_check][col_check] = 0
            else:
                table[row_check][col_check] = 1

def dfs(row, col, cnt):
    # 범위를 넘어섰을 때
    if row >= 9 or col > 9:
        answer = min(answer, cnt)
        return

    if answer <= cnt:
        return

    if col > 9:
        dfs(row+1, 0, cnt)
        return

    if table[row][col] == 1:
        for paper in range(5):
            if can_cover(row, col, paper):
                cover(row, col, paper, True)
                dfs(row, col + 1, cnt + 1)
                cover(row, col, paper, False)
    else:
        dfs(row, col+1, cnt)
    

if __name__ == "__main__":
    for row in range(10):
        table.append(list(map(int, sys.stdin.readline().split(" "))))

    dfs(0, 0, 0)

    if answer == MAX_VAL:
        answer = -1

    print(answer)