target = input()

joi = "JOI"
ioi = "IOI"

joi_count, ioi_count = 0, 0
for idx in range(0, len(target) - 2):
    if target[idx:idx+3] == "JOI":
        joi_count += 1

    if target[idx:idx+3] == "IOI":
        ioi_count += 1

print(joi_count)
print(ioi_count)