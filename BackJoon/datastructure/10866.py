from collections import deque

count = int(input())

container = []
for _ in range(count):
    raw = input()
    raw_list = raw.split(" ")
    container.append(tuple(raw_list))

q = deque()
for raw in container:
    if len(raw) >= 2:
        cmd, data = raw
    else:
        cmd = raw[0]

    if cmd == "push_back":
        q.append(data)
    elif cmd == "push_front":
        q.appendleft(data)
    elif cmd == "front":
        if q:
            print(q[0])
        else:
            print(-1)
    elif cmd == "back":
        if q:
            print(q[-1])
        else:
            print(-1)
    elif cmd == "size":
        print(len(q))
    elif cmd == "empty":
        if len(q) == 0:
            print(1)
        else:
            print(0)
    elif cmd == "pop_front":
        if not q:
            print(-1)
        else:
            print(q.popleft())
    elif cmd == "pop_back":
        if not q:
            print(-1)
        else:
            print(q.pop())