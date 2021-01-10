import sys

if __name__ == "__main__":
    number = int(sys.stdin.readline())
    
    cute = 0
    not_cute = 0
    for _ in range(number):
        response = int(sys.stdin.readline())

        if response == 1:
            cute += 1
        else:
            not_cute += 1

    if cute > not_cute:
        print("Junhee is cute!")
    else:
        print("Junhee is not cute!")