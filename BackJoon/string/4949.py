import sys

if __name__ == "__main__":
    while True:
        raw_string = sys.stdin.readline().replace("\n", "")
        if raw_string == ".":
            break

        braket_table = {"(":")", "[":"]"}

        stack = []
        result = True
        for char in raw_string:
            if char in braket_table:
                stack.append(char)
            elif char in braket_table.values():
                if len(stack) > 0 and braket_table[stack[-1]] == char:
                    stack.pop()
                    continue
                else:
                    result = False
                    break
        
        if result and len(stack) == 0:
            print("yes")
        else:
            print("no")
        