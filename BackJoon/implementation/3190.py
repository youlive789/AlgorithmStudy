import sys

if __name__ == "__main__":
    board_size = int(sys.stdin.readline())
    board = [[0 for _ in range(board_size)] for _ in range(board_size)]

    apple_count = int(sys.stdin.readline())
    for _ in range(apple_count):
        row, col = list(map(int, sys.stdin.readline().split(" ")))
        board[row-1][col-1] = 1

    move_commands = []
    commands_count = int(sys.stdin.readline())
    for _ in range(commands_count):
        second, command = sys.stdin.readline().replace("\n", "").split(" ")
        move_commands.append([int(second), command])

    # 오른쪽 회전일 경우 idx + 1, 왼쪽 회전일 경우 idx - 1
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    idx_direction = 0
    x_position, y_position = 0, 0

    score = 0
    snake = [[0, 0]]
    while 0 <= y_position < board_size and 0 <= x_position < board_size:
        # 커맨드 조건에 맞는다면
        if move_commands and move_commands[0][0] == score:
            if move_commands[0][1] == "D":
                idx_direction += 1
            elif move_commands[0][1] == "L":
                idx_direction -= 1
            
            if idx_direction > 3:
                idx_direction = 0
            elif idx_direction < 0:
                idx_direction = 3
            move_commands.pop(0)
            
        # 머리 다음칸 이동
        board[y_position][x_position] = 2
        x_position += dx[idx_direction]
        y_position += dy[idx_direction]
        score += 1

        if 0 > y_position or board_size <= y_position or 0 > x_position or board_size <= x_position:
            break

        if board[y_position][x_position] == 2:
            break

        # 이동한 칸에 사과가 없었다면
        if board[y_position][x_position] != 1:
            # 꼬리 위치 초기화
            y, x = snake[0]
            board[y][x] = 0
            snake.pop(0)
        snake.append([y_position, x_position])

    print(score)