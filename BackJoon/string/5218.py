import sys

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    for _ in range(size):
        a, b = sys.stdin.readline().replace("\n", "").split(" ")

        word_size = len(a)
        distances = []
        for idx in range(word_size):
            a_char = ord(a[idx])
            b_char = ord(b[idx])
            
            if a_char <= b_char:
                distances.append(b_char - a_char)
            else:
                distances.append(b_char + 26 - a_char)

        print("Distances:", " ".join(list(map(str, distances))))
