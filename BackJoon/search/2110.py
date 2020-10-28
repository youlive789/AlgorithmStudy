import sys
from itertools import combinations

"""
reference:
https://mygumi.tistory.com/301
"""

if __name__ == "__main__":
    house_count, target_count = list(map(int, sys.stdin.readline().split(" ")))

    house_container = []
    for _ in range(house_count):
        house_container.append(int(sys.stdin.readline()))

    house_container.sort()

    min_distance = 1
    max_distance = house_container[-1] - house_container[0]

    answer = 0
    while min_distance <= max_distance:
        mid = (min_distance + max_distance) // 2
        start = house_container[0]
        count = 1

        for i in range(1, house_count):
            distance = house_container[i] - start
            if mid <= distance:
                count += 1
                start = house_container[i]

        if count >= target_count:
            answer = mid
            min_distance = mid + 1
        else:
            max_distance = mid - 1

    print(answer)