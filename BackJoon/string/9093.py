import sys

if __name__ == "__main__":
    sentence_count = int(sys.stdin.readline())

    sentences = []
    for _ in range(sentence_count):
        sentence = sys.stdin.readline().replace("\n", "").split(" ")
        sentence = list(map(lambda x: x[::-1], sentence))
        sentence = " ".join(sentence)
        sentences.append(sentence)

    for sentence in sentences:
        print(sentence)