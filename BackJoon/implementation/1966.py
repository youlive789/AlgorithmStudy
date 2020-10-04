import sys
from collections import deque

def rotate_documents(ziped_documents):
    zip_max = max(ziped_documents)[0]
    while ziped_documents[0][0] != zip_max:
        ziped_documents.rotate(-1)

if __name__ == "__main__":
    cases = int(sys.stdin.readline())

    answer = []
    for _ in range(cases):
        count, target = list(map(int, sys.stdin.readline().split(" ")))
        documents = list(map(int, sys.stdin.readline().split(" ")))
        index_documents = list(range(len(documents)))

        checker = documents[target]
        ziped_documents = list(zip(documents, index_documents))
        ziped_documents = deque(ziped_documents)

        result = 0
        printed, index_printed = None, None
        while printed != checker or index_printed != target:
            # print(ziped_documents)
            rotate_documents(ziped_documents)
            printed, index_printed = ziped_documents.popleft()
            result += 1
        answer.append(result)

    for item in answer:
        print(item)
        

