import sys

def quick_sort(numbers):
    def sort(low, high):
        if high <= low:
            return

        mid = partition(low, high)
        sort(low, mid - 1)
        sort(mid, high)

    def partition(low, high):
        pivot = numbers[(low + high) // 2]
        while low <= high:
            while numbers[low] < pivot:
                low += 1
            while numbers[high] > pivot:
                high -= 1
            if low <= high:
                numbers[low], numbers[high] = numbers[high], numbers[low]
                low, high = low + 1, high - 1
        return low

    return sort(0, len(numbers) - 1)

if __name__ == "__main__":
    size = int(sys.stdin.readline())

    numbers = []
    for _ in range(size):
        numbers.append(int(sys.stdin.readline()))

    quick_sort(numbers)
    for num in numbers:
        print(num)