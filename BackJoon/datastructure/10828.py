import sys

if __name__ == "__main__":
    cnt_commands = int(sys.stdin.readline())

    commands = []
    for _ in range(cnt_commands):
        commands.append(sys.stdin.readline().replace("\n", "").split(" "))

    stack = []
    for command in commands:
        if command[0] == "push":
            stack.append(int(command[1]))
        elif command[0] == "top" and len(stack) > 0:
            print(stack[-1])
        elif command[0] == "size":
            print(len(stack))
        elif command[0] == "pop" and len(stack) > 0:
            print(stack[-1])
            stack.pop()
        elif command[0] == "empty":
            if len(stack) > 0:
                print(0)
            else:
                print(1)
        else:
            print(-1)