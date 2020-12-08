import sys

def get_length(first, second, count):
    if first == second:
        return count
    
    result = 0
    if first > second:
        result += get_length(first // 2, second, count + 1)
    elif first < second:
        result += get_length(first, second // 2, count + 1)

    return result
    

if __name__ == "__main__":
    first, second = list(map(int, sys.stdin.readline().split(" ")))

    count = get_length(first, second, 0)
    print(count)