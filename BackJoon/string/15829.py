length = int(input())
target = input()

hash_value = 0
mul_index = 0
for char in target:
    hash_value += (ord(char) - 96) * int(pow(31, mul_index))
    mul_index += 1

print(hash_value % 1234567891)