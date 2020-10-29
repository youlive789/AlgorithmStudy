import sys
from itertools import combinations

if __name__ == "__main__":
    player_count = int(sys.stdin.readline())

    ability_table = []
    for _ in range(player_count):
        ability_table.append(list(map(int, sys.stdin.readline().split(" "))))

    answer = sys.maxsize
    combination_table = list(combinations(range(len(ability_table)), player_count // 2))
    
    for idx in range(len(combination_table) // 2):
        star_team = list(combination_table[idx])
        link_team = list(combination_table[len(combination_table) - idx - 1])

        star_team_score = 0
        for i, j in list(combinations(star_team, 2)):
            star_team_score += ability_table[i][j]
            star_team_score += ability_table[j][i]

        link_team_score = 0
        for i, j in list(combinations(link_team, 2)):
            link_team_score += ability_table[i][j]
            link_team_score += ability_table[j][i]

        answer = min(answer, abs(star_team_score - link_team_score))

        
    print(answer)