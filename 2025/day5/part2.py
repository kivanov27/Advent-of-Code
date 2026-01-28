import re

ranges = []

with open("input.txt", 'r') as file:
    for line in file:
        line = line.strip()
        if not line:
            break
        x, y = map(int, re.findall(r'\d+', line))
        ranges.append([x, y])

ranges.sort()
merged = []

for start, end in ranges:
    if not merged or start > merged[-1][1] + 1:
        merged.append([start, end])
    else:
        merged[-1][1] = max(end, merged[-1][1])

print(sum(end - start + 1 for start, end in merged))
