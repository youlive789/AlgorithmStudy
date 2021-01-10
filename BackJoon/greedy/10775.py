import sys

gate_count = int(input())
plane_count = int(input())

gates = [True for _ in range(gate_count+1)]

answer = 0
for _ in range(plane_count):
    plane_dock = int(sys.stdin.readline())

    cannot_find = True
    for idx in range(plane_dock, 0, -1):
        if gates[idx]:
            cannot_find = False
            gates[idx] = False
            answer += 1
            break
   
    if cannot_find:
        break

print(answer)