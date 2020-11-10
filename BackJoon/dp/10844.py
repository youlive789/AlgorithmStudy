import sys

def find_step_number(length, last_num, container, cache):

    # 컨테이너 길이가 N이라면
    if length == 0:
        return 1

    if cache[length][last_num] != -1:
        return cache[length][last_num]

    # 숫자 0-9까지 반복
    count = 0
    for num in range(0, 10):
        # 컨테이너가 비어있고 숫자가 0이라면
        if len(container) == 0 and num == 0:
            continue

        # 지금 숫자가 컨테이너 이전 숫자와의 차이가 1이라면
        if len(container) == 0 or abs(num - container[-1]) == 1:
            # 숫자 삽입
            container.append(num)
            # 재귀호출
            count += find_step_number(length - 1, num, container, cache)
            # 숫자 빼기
            container.pop()

    cache[length][last_num] = count
    return count

if __name__ == "__main__":
    length = int(sys.stdin.readline())
    cache = [ [-1 for _ in range(10)] for _ in range(length + 1)]
    count = find_step_number(length, 0, [], cache)
    print(count % 1000000000)    