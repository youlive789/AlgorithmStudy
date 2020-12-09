from collections import Counter

if __name__ == "__main__":
    name = list(input())
    name_count = Counter(name)

    odd_check = len(name) % 2
    for key, count in name_count.items():
        if count % 2 != 0:
            if odd_check == 1:
                odd_check = 0
                continue
            print("I'm Sorry Hansoo")
            exit()
    
    string_container = ['' for _ in range(len(name))]

    idx = 0
    keys = sorted(list(name_count.keys()))
    for key in keys:
        
        limit = 0
        now_word_count = name_count[key]
        if now_word_count % 2 == 1:
            limit = 1

        while now_word_count > limit:
            string_container[idx] = key
            string_container[len(name) - idx - 1] = key
            now_word_count -= 2
            idx += 1

        if limit == 1:
            string_container[len(name) // 2] = key

    print("".join(string_container))