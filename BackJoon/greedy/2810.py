count = int(input())
seats = list(input())

index, last, couple_count = 0, "", 0
while index < len(seats):
    if index == 0:
        seats.insert(index, "*")
        index += 1
    elif seats[index] == "S":
        last = seats[index]
        seats.insert(index, "*")
        index += 1
    elif seats[index] == "L":
        if last != "L":
            last = seats[index]
            seats.insert(index, "*")
            index += 2
            couple_count += 1
        elif couple_count == 1:
            last = seats[index]
            seats.insert(index, "*")
            index += 2
            couple_count = 0
    index += 1

answer = 0
for char in "".join(seats):
    if char == "*":
        answer += 1

print(answer + 1)