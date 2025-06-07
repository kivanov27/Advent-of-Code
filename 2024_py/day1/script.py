FILE = 'input.txt'
a = []
b = []
# sum = 0
count = {}
sum2 = 0

with open(FILE, 'r') as file:
    for line in file:
        a.append(line.split('   ')[0])
        b.append(line.split('   ')[1][0:-1])

a.sort()
b.sort()

for i in range(0, len(a)):
    # part 1
    # sum += abs(int(a[i]) - int(b[i]))
    
    # part 2
    for j in range(0, len(b)):
        if a[i] == b[j]:
            count[a[i]] = count.get(a[i], 0) + 1

for key, val in count.items():
    sum2 += int(key) * int(val)

print(sum2)
