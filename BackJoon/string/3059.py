alpha_sum = sum(list(range(65, 91)))

cases = int(input())
for _ in range(cases):
    target = input()
    target_answer = alpha_sum

    used = {}
    for char in target:
        if char not in used:
            target_answer -= ord(char)
            used[char] = 0

    print(target_answer)