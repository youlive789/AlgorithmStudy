from collections import deque

length = int(input())
expression = input()

expressions = []
for i in range(length-1):
    for j in range(i+1, length):
        if expression[j].isdigit() and expression[i].isdigit() and j - i == 2:
            target = expression[:i] + str(eval("(" + expression[i:j+1] + ")")) + expression[j+1:]

            container = []
            idx_last = 0
            for idx in range(len(target)):
                if not target[idx].isdigit():
                    container.append(target[idx_last:idx])
                    idx_last = idx+1
                    container.append(target[idx])
            container.append(target[idx_last:])
            expressions.append(container)

answer = 0
for expression in expressions:
    q = deque(list(expression))
    first, oper, second = "", "", ""
    while q:
        poped = q.popleft()
        if poped.isdigit():
            if first == "":
                first = poped
            elif second == "":
                second = poped
        else:
            oper = poped

        print(expression, first, oper, second)

        if first != "" and oper != "" and second != "":
            first = str(eval(first + oper + second))
            oper, second = "", ""
    print(expression, first, oper, second)
    answer = max(int(first), answer)

print(answer)