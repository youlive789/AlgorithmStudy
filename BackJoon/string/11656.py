import sys

if __name__ == "__main__":
    
    string = sys.stdin.readline().replace("\n", "")
    
    prefix = []
    for idx in range(0, len(string)):
        prefix.append(string[idx:])

    prefix.sort()
    for item in prefix:
        print(item)
