
def star(height, x, y) :
    if height == 0 :
        return

    if int(x / height) % 3 == 1 and int(y / height) % 3 == 1 :
        print(" ", end='')
    else:
        if int(height / 3) == 0  :
            print("*", end='')
        else :
            star(height / 3, x, y)

if __name__ == "__main__":
    N = 27
    for x in range(N) :
        for y in range(N) :
            star(N, x, y)
        print("\n", end='')
