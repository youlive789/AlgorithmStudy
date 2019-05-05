
def sum_(number):
    answer = 0
    while number >= 1 :
        answer += number
        number -= 1
    return answer

def recursiveSum(number):
    if number == 1 :
        return number
    return number + recursiveSum(number - 1) 

if __name__ == "__main__":
    print("일반적인 더하기 함수 : " , sum_(10))
    print("재귀호출 더하기 함수 : " , recursiveSum(10))