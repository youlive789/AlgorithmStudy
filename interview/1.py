def solve(target):
    size_col = len(target[0])
    size_row = len(target)

    moved = [[False] * size_col] * size_row

    cnt_area = 0
    max_area_size = 0
    current_number = 0
    current_area_size = 0

    for row in range(size_row):
        for col in range(size_col):
            # 요소가 0이거나 이미 찾은 영역이라면
            if target[row][col] == 0 or moved[row][col] == True :
                continue
            # 0이 아니고
            else: 
                cnt_area += 1
                # 현재 좌표 저장
                tmp_row, tmp_col = row, col
                # 현재 숫자 저장
                current_number = target[row][col]
                current_area_size = 0
                
                print(row, " ", col)
                # 좌표가 밖으로 나가지 않았고, 현재 숫자를 찾을때까지 반복
                while tmp_row >= 0 and tmp_row < size_row and tmp_col >= 0 and tmp_col < size_col and target[tmp_row][tmp_col] == current_number:
                    print("현재 순회 좌표 => ", tmp_row, " ", tmp_col, " ")

                    # 순서이동 좌표값이 현재 숫자와 같다면
                    if target[tmp_row][tmp_col] == current_number:
                        current_area_size += 1
                    # 순서이동 좌표와 현재 좌표가 다르다면
                    else:
                        break

                    # 우, 하, 좌, 순서이동 
                    if (tmp_col + 1 >= 0 and tmp_col + 1 < size_col) and (target[tmp_row][tmp_col + 1] == current_number) and (moved[tmp_row][tmp_col + 1] == False):
                        moved[tmp_row][tmp_col + 1] = True
                        tmp_col += 1
                        continue
                    elif (tmp_col - 1 >= 0 and tmp_col - 1 < size_col) and (target[tmp_row][tmp_col - 1] == current_number) and (moved[tmp_row][tmp_col - 1] == False):
                        moved[tmp_row][tmp_col - 1] = True
                        tmp_col -= 1
                        continue
                    elif (tmp_row + 1 >= 0 and tmp_row + 1 < size_col) and (target[tmp_row + 1][tmp_col] == current_number) and (moved[tmp_row + 1][tmp_col] == False):
                        moved[tmp_row + 1][tmp_col] = True
                        tmp_row += 1
                        continue
                    else:
                        break

            if current_area_size > max_area_size :
                max_area_size = current_area_size

    return [cnt_area, max_area_size]


if __name__ == "__main__":
    print(solve([[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]])) # [2, 3]