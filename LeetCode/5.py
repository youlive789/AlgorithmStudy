target = "babdac"

s_length = len(target)
length = len(target)
start = 0
end = length

answer = ""
max_length = 0

while length > 1:
    if end > s_length:
        start = 0
        end = length - 1
        length -= 1

    s = target[start:end]
    is_palindrome = False
    mid = int(len(s) / 2)
    if len(s) % 2 == 0:
        if s[:mid] == s[mid:][::-1]:
            is_palindrome = True
    else:
        if s[:mid] == s[mid+1:][::-1]:
            is_palindrome = True

    if is_palindrome :
        if max_length < len(s):
            max_length = len(s)
            answer = s

    start += 1
    end += 1

print(answer)

# answer = ""
# max_length = 0
# for i in range(len(target)):
#     for j in range(len(target) + 1):
#         if i < j:
#             s = target[i:j]
#             is_palindrome = False
#             mid = int(len(s) / 2)
#             print(s, " ", mid)
#             if len(s) % 2 == 0:
#                 if s[:mid] == s[mid:][::-1]:
#                     is_palindrome = True
#             else:
#                 if s[:mid] == s[mid+1:][::-1]:
#                     is_palindrome = True

#             if is_palindrome :
#                 if max_length < len(s):
#                     max_length = len(s)
#                     answer = s

# print(answer)