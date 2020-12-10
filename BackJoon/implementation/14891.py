import sys
from collections import deque

if __name__ == "__main__":
    gears = []
    for _ in range(4):
        gears.append(deque(list(map(int, list(sys.stdin.readline().replace("\n", ""))))))

    rotates = []
    rotate_count = int(sys.stdin.readline())
    for _ in range(rotate_count):
        rotates.append(list(map(int, sys.stdin.readline().split(" "))))

    for number_gear, direction in rotates:
        have_to_ratate = [0, 0, 0, 0]

        idx_gear = number_gear - 1
        have_to_ratate[idx_gear] = direction

        # 정방향 기어들의 회전방향을 결정한다.
        temp_direction = direction
        idx_last_gear, idx_near_gear = idx_gear, idx_gear
        while idx_near_gear < 3:
            idx_near_gear += 1

            temp_direction *= -1
            if gears[idx_last_gear][2] != gears[idx_near_gear][6]:
                have_to_ratate[idx_near_gear] = temp_direction
            else:
                break

            idx_last_gear = idx_near_gear

        # 역방향 기어들의 회전방향을 결정한다.
        temp_direction = direction
        idx_last_gear, idx_near_gear = idx_gear, idx_gear
        while idx_near_gear > 0:
            idx_near_gear -= 1

            temp_direction *= -1
            if gears[idx_last_gear][6] != gears[idx_near_gear][2]:
                have_to_ratate[idx_near_gear] = temp_direction
            else:
                break

            idx_last_gear = idx_near_gear

        # 기어들을 회전시킨다.
        for idx, direct in enumerate(have_to_ratate):
            gears[idx].rotate(direct)

    answer = 0
    for idx, gear in enumerate(gears):
        answer += (2**idx) * gear[0]

    print(answer)