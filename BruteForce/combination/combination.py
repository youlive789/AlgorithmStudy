
def combination():
    for i in range(1, 11):
        for j in range(i+1, 11):
            print(i , "," , j)

def recursiveCombination(totNumber, picked, toPick):
    # 기저사례 : 더 이상 뽑아야할 숫자가 없으면 출력
    if toPick == 0 :
        for num in picked:
            print(num)
        print()
        return

    # 맨 처음 뽑을 수를 계산한다.
    if picked :
        smallest = picked[-1] + 1
    else :
        smallest = 0
        
    # 뽑아야 될 수만큼 숫자를 뽑는다. -> 재귀
    for i in range(smallest, totNumber):
        picked.append(i)
        recursiveCombination(totNumber, picked, toPick-1)
        picked.pop()

if __name__ == "__main__":
    picked = []
    recursiveCombination(10, picked, 3)