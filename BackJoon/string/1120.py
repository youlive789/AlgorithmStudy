import sys

def get_difference(short, long):

    initial_difference = len(long) - len(short)

    difference = sys.maxsize
    for idx_position in range(initial_difference):
        idx_short, now_difference = 0, 0
        for idx in range(idx_position, len(long) - initial_difference + idx_position):
            if short[idx_short] != long[idx]:
                now_difference += 1
            idx_short += 1

        difference = min(difference, now_difference)

    return difference 


if __name__ == "__main__":
    a, b = list(sys.stdin.readline().split(" "))
    print(get_difference(a, b))