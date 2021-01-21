test_case = int(input())

for _ in range(test_case):
    first_note_count = int(input())
    first_note = input().split(" ")

    first_note_dict = {}
    for ele in first_note:
        first_note_dict[ele] = 0

    second_note_count = int(input())
    second_note = input().split(" ")
    for ele in second_note:
        if ele not in first_note_dict:
            print(0)
        else:
            print(1)