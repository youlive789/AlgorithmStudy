target = input()
stack = []

answer, last = 0, ""
for char in target:
    if char == "(":
        stack.append(char)
    else:
        stack.pop()
        if last == "(":
            answer += len(stack)
        elif last == ")":
            answer += 1
    last = char

print(answer)