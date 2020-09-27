import sys
def cyclone(size, clockwise):    
    start_position = {
        True: [[0, 0], [0, size - 1], [size - 1, size - 1], [size - 1, 0]],
        False: [[0, size - 1], [0, 0], [size - 1, 0], [size -1, size - 1]],
    }

    direction = {
        True: [[0, 1], [1, 0], [0, -1], [-1, 0]],
        False: [[0, -1], [1, 0], [0, 1], [-1, 0]],
    }

    answer = make_grid(size, clockwise, start_position, direction)
    return answer

def make_grid(size, clockwise, start_position, direction):

    answer = [[0 for _ in range(size)] for _ in range(size)]

    idx_start = 0
    idx_direction, cnt_direction, limit_direction = 0, 0, size - 1
    check = 1

    row, col = start_position[clockwise][idx_start][0], start_position[clockwise][idx_start][1]
    even_center_position = [size // 2, (size // 2) - 1]

    while True:

        answer[row][col] = check
        cnt_direction += 1
        check += 1

        if idx_start == 3:
            if size % 2 == 1 and row == size // 2 and col == size // 2:
                break
            elif size % 2 == 0 and row in even_center_position and col in even_center_position:
                break

        if size % 2 != 0:
            if row == size // 2 and col == size // 2:
                idx_start += 1
                check, cnt_direction = 1, 0
                limit_direction = size - 1
                idx_direction = idx_start
                row, col = start_position[clockwise][idx_start][0], start_position[clockwise][idx_start][1]
                continue
        else:
            if row in even_center_position and col in even_center_position:
                idx_start += 1
                check, cnt_direction = 1, 0
                limit_direction = size - 1
                idx_direction = idx_start
                row, col = start_position[clockwise][idx_start][0], start_position[clockwise][idx_start][1]
                continue

        if cnt_direction == limit_direction:
            idx_direction += 1
            if idx_direction == 4:
                idx_direction = 0

            if limit_direction <= 2:
                limit_direction -= 1
            else:
                limit_direction -= 2
            cnt_direction = 0
        
        row += direction[clockwise][idx_direction][0]
        col += direction[clockwise][idx_direction][1]

    return answer

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    print(cyclone(size, True))
    print()
    print(cyclone(size, False))