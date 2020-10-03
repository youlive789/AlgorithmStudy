import sys

if __name__ == "__main__":
    word = sys.stdin.readline().replace("\n", "")
    
    alphabet_dict = {}
    for char_num in range(ord('a'), ord('z') + 1):
        char = chr(char_num)
        alphabet_dict[char] = 0

    for char in word:
        if char not in alphabet_dict:
            alphabet_dict[char] = 1
        else:
            alphabet_dict[char] += 1

    for char, count in alphabet_dict.items():
        print(count, end=" ")
        
    