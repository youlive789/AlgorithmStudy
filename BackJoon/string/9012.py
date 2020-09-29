import sys

if __name__ == "__main__":
    cnt = int(sys.stdin.readline())
    
    for _ in range(cnt):
        stack = []
        vps = sys.stdin.readline().replace("\n", "")
        
        is_vps = True
        for char in vps:
            if char == "(":
                stack.append(char)
            else:
                if len(stack) == 0:
                    is_vps = False
                else:
                    stack.pop()

        if len(stack) > 0:
            is_vps = False
            
        if is_vps:
            print("YES")
        else:
            print("NO")