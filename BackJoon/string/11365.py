import sys

if __name__ == "__main__":
    string_container = []
    while True:
        input_string = sys.stdin.readline().replace("\n", "")
        if input_string == "END":
            break
        string_container.append(input_string[::-1])

    for string in string_container:
        print(string)