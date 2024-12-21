import re

total = 0
matches = []
pattern = r"mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\)"
do = True

with(open('input.txt', 'r') as file):
    for line in file:
        matches.extend(re.findall(pattern, line))

for match in matches:
    if match == 'do()':
        do = True
    elif match == "don't()":
        do = False
    elif re.match(r'mul\(\d{1,3},\d{1,3}\)', match):
        if do:
            nums = re.findall(r'\d{1,3}', match)
            total += int(nums[0]) * int(nums[1])

print(total)
