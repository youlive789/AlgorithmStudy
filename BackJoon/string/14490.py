
if __name__ == "__main__":
    first, second = list(map(int, input().split(":")))
    
    smaller = min(first, second)
    for i in range(2, smaller + 1):
        while first % i == 0 and second % i == 0:
            first //= i
            second //= i

    print(str(first) + ":" + str(second))
    