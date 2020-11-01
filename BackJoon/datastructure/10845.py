import sys
from collections import deque

if __name__ == "__main__":
    
    commands = []
    count = int(sys.stdin.readline())
    for _ in range(count):
        commands.append(sys.stdin.readline().replace("\n", "").split(" "))

    q = deque([])
    for command in commands:
        if command[0] == "push":
            q.append(command[1])
        elif command[0] == "pop":
            if len(q) == 0:
                print(-1)
            else:
                print(q.popleft())
        elif command[0] == "size":
            print(len(q))
        elif command[0] == "empty":
            if len(q) == 0:
                print(1)
            else:
                print(0)
        elif command[0] == "front":
            if len(q) == 0:
                print(-1)
            else:
                print(q[0])
        elif command[0] == "back":
            if len(q) == 0:
                print(-1)
            else:
                print(q[-1])