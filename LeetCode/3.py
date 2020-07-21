
def lengthOfLongestSubstring(s: str) -> int:
    substr = ""
    max_length = 0

    for i in range(len(s)):
        found_idx = substr.find(s[i])
        if (found_idx > -1) :
            substr = substr[found_idx + 1:]

        substr += s[i]

        if (max_length < len(substr)) :
            max_length = len(substr)

    return max_length

if __name__ == "__main__":
    print(lengthOfLongestSubstring("abcabcbb"))