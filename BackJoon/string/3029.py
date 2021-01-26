first_time = list(map(int, input().split(":")))
second_time = list(map(int, input().split(":")))

# sec
sec = second_time[2] - first_time[2]
if sec < 0:
    sec += 60
    second_time[1] -= 1

# min
mins = second_time[1] - first_time[1]
if mins < 0:
    mins += 60
    second_time[0] -= 1

# hour
hour = second_time[0] - first_time[0]
if hour < 0:
    hour += 24

if hour == 0 and mins == 0 and sec == 0:
    hour = 24

print("{0:02d}:{1:02d}:{2:02d}".format(hour, mins, sec))
