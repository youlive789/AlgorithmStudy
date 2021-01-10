name = ["Soongsil", "Korea", "Hanyang"]
score = list(map(int, input().split()))

total = sum(score) 
min_index = score.index(min(score))

if total >= 100:
    print("OK")
else:
    print(name[min_index])