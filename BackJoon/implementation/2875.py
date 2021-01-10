import sys

if __name__ == "__main__":
    girls, boys, num_internship = list(map(int, sys.stdin.readline().split(" ")))

    max_team = 0
    for intern in range(num_internship+1):
        calc_girls, calc_boys = girls, boys

        calc_boys -= intern
        calc_girls -= (num_internship - intern)

        temp = calc_girls // 2
        if calc_boys > temp:
            max_team = max(temp, max_team)
        else:
            max_team = max(calc_boys, max_team)

        
    print(max_team)