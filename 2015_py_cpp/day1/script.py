file = open('input.txt', 'r')

floor = 0
position = 0

while 1:
    char = file.read(1)
    if not char:
        break
    elif floor == -1:
        print(position)
        break
    elif char == '(':
        floor += 1
        position += 1
    elif char == ')':
        floor -= 1
        position += 1

file.close()
print(floor)
