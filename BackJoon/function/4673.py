
def self_number(number):
    self_num = number
    while number > 0:
        self_num += number % 10
        number = number // 10
    return self_num

if __name__ == "__main__":

    self_numbers = [True] * 15000
    for idx in range(len(self_numbers[:10000])):
        if idx == 0:
            continue

        self_numbers[self_number(idx)] = False


    for idx in range(len(self_numbers[:10000])):
        if idx == 0:
            continue
        if self_numbers[idx]:
            print(idx)