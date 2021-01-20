import math

targetString = input()

def prime(number):
    if 1 <= number <= 3:
        return True
    else:
        limit_number = int(math.sqrt(number)) + 1
        for idx in range(2, limit_number):
            if number % idx == 0:
                return False
        return True

string_number = 0
for char in targetString:
    char_number = ord(char)
    if 97 <= char_number <= 122:
        string_number += (char_number - 96)
    elif 65 <= char_number <= 90:
        string_number += (char_number - 38)

if prime(string_number):
    print("It is a prime word.")
else:
    print("It is not a prime word.")