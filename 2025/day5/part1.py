import re

populating = True
ranges = []
fresh = 0

with open("input.txt", 'r') as file:
    for line in file:
        line = line.strip()
        if (line == ""):
            populating = False
            continue
        if (populating):
            matches = re.findall(r'\d+', line)
            res = [int(x) for x in matches]
            ranges.append(res)
        else:
            num = int(line)
            for [x, y] in ranges:
                # print(f"is {num} in {x}-{y}")
                if (num >= x and num <= y):
                    fresh += 1
                    # print("yes")
                    break
                # else:
                #     print("no")

print(f"fresh: {fresh}")
