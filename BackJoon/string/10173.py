while True:
    target = input()
    if target == "EOI":
        break

    if target.lower().find("nemo") > -1:
        print("Found")
    else:
        print("Missing")