import sys
import re

if __name__ == "__main__":
    eq = sys.stdin.readline().replace("\n", "")
    
    eq = re.split("([+-])", eq)
    for idx in range(len(eq)):
        if eq[idx].isdigit():
            index = 0
            for i, c in enumerate(eq[idx]):
                if c != "0":
                    index = i
                    break
            eq[idx] = eq[idx][i:]

    for idx in range(len(eq)):
        if eq[idx] == "+":
            eq[idx-1] = "(" + eq[idx-1]
            eq[idx+1] = eq[idx+1] + ")"
    
    print(eval("".join(eq)))