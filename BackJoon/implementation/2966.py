def calc_scores(answer, score_table):
    score_table[0] = calc_a(answer)
    score_table[1] = calc_b(answer)
    score_table[2] = calc_g(answer)
    return score_table

def calc_a(answer):
    score = 0
    target = list(answer)
    for idx, char in enumerate(target):
        idx_mod = idx % 3
        if idx_mod == 0 and char == "A":
            score += 1
        elif idx_mod == 1 and char == "B":
            score += 1
        elif idx_mod == 2 and char == "C":
            score += 1
    return score

def calc_b(answer):
    score = 0
    target = list(answer)
    for idx, char in enumerate(target):
        idx_mod = idx % 4
        if (idx_mod == 0 or idx_mod == 2) and char == "B":
            score += 1
        elif idx_mod == 1 and char == "A":
            score += 1
        elif idx_mod == 3 and char == "C":
            score += 1
    return score

def calc_g(answer):
    score = 0
    target = list(answer)
    for idx, char in enumerate(target):
        idx_mod = idx % 6
        if (idx_mod == 0 or idx_mod == 1) and char == "C":
            score += 1
        elif (idx_mod == 2 or idx_mod == 3) and char == "A":
            score += 1
        elif (idx_mod == 4 or idx_mod == 5) and char == "B":
            score += 1
    return score

length = int(input())
answer = input()
score_table = [0, 0, 0]
score_table = calc_scores(answer, score_table)

max_score = max(score_table)
print(max_score)
for idx, score in enumerate(score_table):
    if score == max_score:
        if idx == 0:
            print("Adrian")
        elif idx == 1:
            print("Bruno")
        else:
            print("Goran")