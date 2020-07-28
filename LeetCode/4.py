def findMedianSortedArrays(nums1, nums2) -> float:
    answer = 0.0
    numbers = nums1 + nums2
    numbers.sort()
    print(numbers)
    len_numbers = len(numbers)
    if len_numbers % 2 == 0:
        answer = (numbers[int(len_numbers / 2) - 1] + numbers[int(len_numbers / 2)]) / 2
    else:
        answer = numbers[int(len_numbers / 2)]

    return answer

if __name__ == "__main__":
    print(findMedianSortedArrays([1,2], [3]))
    print(findMedianSortedArrays([1,1], [1,2]))