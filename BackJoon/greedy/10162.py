import sys

if __name__ == "__main__":
    time = int(sys.stdin.readline())

    button_table = [0, 0, 0]
    while time > 0:
        if time >= 300:
            button_table[0] += time // 300 
            time %= 300            
        elif time >= 60:
            button_table[1] += time // 60
            time %= 60
        elif time >= 10:
            button_table[2] += time // 10
            time %= 10
        else:
            print(-1)
            exit()

    for t in button_table:
        print(t, end=" ")