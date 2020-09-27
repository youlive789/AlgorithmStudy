import sys

"""
1 2 3 4 1    1 2 3 4 5 1
4 5 6 5 2    5 6 7 8 6 2
3 8 7 6 3    4 8 9 9 7 3
2 5 6 5 4    3 7 9 9 8 4
1 4 3 2 1    2 6 8 7 6 5
             1 5 4 3 2 1

1 4 3 2 1    1 5 4 3 2 1
2 5 6 5 4    2 6 8 7 6 5
3 6 7 6 3    3 7 9 9 8 4
4 5 6 5 2    4 8 9 9 7 3
1 2 3 4 1    5 6 7 8 6 2
             1 2 3 4 5 1
"""
def cyclone(size, clockwise):    
    start_position = {
        True: [[0, 0], [0, size - 1], [size - 1, size - 1], [size - 1, 0]],
        False: [[0, size - 1], [size -1, size - 1], [size - 1, 0], [0, 0]],
    }

    direction = {
        True: [[0, 1], [1, 0], [0, -1], [-1, 0]],
        False: [[0, -1], [-1, 0], [0, 1], [1, 0]],
    }

    even_center_position = {
        True: [[size // 2, size // 2], [size // 2, (size // 2) - 1], [(size // 2) - 1, (size // 2) - 1], [(size // 2) - 1, size // 2]],
        False: [[size // 2, (size // 2) - 1], [(size // 2) - 1, (size // 2) - 1], [(size // 2) - 1, (size // 2)], [size // 2, size // 2]],
    }

    answer = make_grid(size, clockwise, start_position, direction, even_center_position)
    return answer

def make_grid(size, clockwise, start_position, direction, even_center_position):

    answer = [[0 for _ in range(size)] for _ in range(size)]

    idx_start = 0
    idx_direction, cnt_direction, limit_direction = 0, 0, size - 1
    check = 1

    row, col = start_position[clockwise][idx_start][0], start_position[clockwise][idx_start][1]

    while True:

        answer[row][col] = check
        print(answer)
        cnt_direction += 1
        check += 1

        # 종료
        if idx_start == 3:
            if size % 2 == 1 and row == size // 2 and col == size // 2:
                break
            elif size % 2 == 0 and row == even_center_position[clockwise][idx_start][0] and col == even_center_position[clockwise][idx_start][1]:
                break

        # 중앙 지점에 도달했다면
        if size % 2 != 0:
            if row == size // 2 and col == size // 2:
                idx_start += 1
                check, cnt_direction = 1, 0
                limit_direction = size - 1
                idx_direction = idx_start
                row, col = start_position[clockwise][idx_start][0], start_position[clockwise][idx_start][1]
                continue
        else:
            if row == even_center_position[clockwise][idx_start][0] and col == even_center_position[clockwise][idx_start][1]:
                idx_start += 1
                check, cnt_direction = 1, 0
                limit_direction = size - 1
                idx_direction = idx_start
                row, col = start_position[clockwise][idx_start][0], start_position[clockwise][idx_start][1]
                continue

        if cnt_direction == limit_direction:
            idx_direction += 1
            if idx_direction == 4:
                idx_direction == 0

            if limit_direction == 2:
                limit_direction -= 1
            else:
                limit_direction -= 2
        
        row += direction[clockwise][idx_direction][0]
        col += direction[clockwise][idx_direction][1]

    return answer

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    print(cyclone(3, True))

