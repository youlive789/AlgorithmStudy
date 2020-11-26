import sys
from collections import deque

if __name__ == "__main__":
    q = deque()
    target_string = sys.stdin.readline().replace("\n", "")

    idx_start, idx_end = 0, 0
    is_tag_open = False
    while idx_start < len(target_string):
        if target_string[idx_start] == "<":
            while idx_end < len(target_string) and target_string[idx_end] != ">" :
                idx_end += 1
            idx_end += 1
            q.append(target_string[idx_start:idx_end])
            idx_start = idx_end
        else:
            while idx_end < len(target_string) and target_string[idx_end] != "<":
                idx_end += 1
            q.append(target_string[idx_start:idx_end])
            idx_start = idx_end

    answer_string = ""
    while q:
        string = q.popleft()
        if "<" in string:
            answer_string += string
        else:
            temp_arr = string.split(" ")
            temp_arr = [temp[::-1] for temp in temp_arr]
            answer_string += " ".join(temp_arr)
    
    print(answer_string)        
