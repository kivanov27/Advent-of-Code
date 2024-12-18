import re

total = 0
matches = []
pattern = r'mul\(\d{1,3},\d{1,3}\)'

with(open('input.txt', 'r') as file):
    for line in file:
        matches.extend(re.findall(pattern, line))

for match in matches:
    nums = re.findall(r'\d{1,3}', match)
    total += int(nums[0]) * int(nums[1])

print(total)
