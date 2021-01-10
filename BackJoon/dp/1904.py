import sys

if __name__ == "__main__":
    """
    f(1) = 1
    f(2) = 2, 00 11
    f(3) = 3, 100 001 111
    f(4) = 5, 1100 1001 0011 1111 0000
    f(5) = 8, 11100 11001 10011 00111 11111 00001 10000
    """
    number = int(sys.stdin.readline())
    if number == 1:
        print(number)
        exit()
    elif number == 2:
        print(number)
        exit()

    a = 1
    b = 2
    answer = 0
    for idx in range(3, number + 1):
        answer = a + b
        answer %= 15746
        a, b = b, a
        b = answer
        
    print(answer)