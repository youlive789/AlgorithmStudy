import sys

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    numbers = list(map(int, sys.stdin.readline().split(" ")))

    query = []
    query_size = int(sys.stdin.readline())
    for _ in range(query_size):
        query.append(list(map(int, sys.stdin.readline().split(" "))))

    for q in query:

        is_palindrome = True
        start = q[0] - 1
        end = q[1] - 1
        
        index = 0
        while index <= ((end - start) // 2):
            if numbers[start + index] != numbers[end - index]:
                is_palindrome = False
                break
            index += 1

        if is_palindrome:
            print(1)
        else:
            print(0)