import sys
cases = int(input())

for _ in range(cases):
    length = int(input())
    lumbers = list(map(int, input().split(" ")))
    lumbers.sort()

    container = [0 for _ in range(length)]
    idx_container, idx_lumber = 0, 0
    while idx_lumber + 1 < length:
        container[idx_container], container[length-idx_container-1] = lumbers[idx_lumber], lumbers[idx_lumber+1]
        idx_container += 1
        idx_lumber += 2

    if length % 2 == 1:
        container[length//2] = lumbers[length-1]

    diff = 0
    for idx in range(length//2, 0, -1):
        if abs(container[idx] - container[idx-1]) > diff:
            diff = abs(container[idx] - container[idx-1])
            

    for idx in range(length//2, length-1):
        if abs(container[idx] - container[idx+1]) > diff:
            diff = abs(container[idx] - container[idx+1])
            
    print(diff)
    
