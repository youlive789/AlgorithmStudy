import sys

if __name__ == "__main__":
    ad_length = int(sys.stdin.readline())
    ad_text = sys.stdin.readline().replace("\n", "")

    if len(set(ad_text)) == 1:
        print(1)
        exit()

    length_possible = ad_length
    for length in range(ad_length, 1, -1):
        idx_start = 0
        idx_end = length
        ad_previous = ad_text[idx_start:idx_end]
        while True:
            idx_start += length
            idx_end += length
            ad_current = ad_text[idx_start:idx_end]

            if idx_start >= ad_length:
                break 

            try:
                intersection = ad_previous.index(ad_current)
                if intersection > -1:
                    length_possible = length
            except:
                pass

            ad_previous = ad_current

    print(length_possible)