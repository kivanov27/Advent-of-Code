import hashlib

INPUT='yzbqklnj'
found = False
i = 1

while not found:
    result = hashlib.md5('{}{}'.format(INPUT, i).encode())
    hexResult = result.hexdigest()

    if hexResult[:6] == '000000':
        found = True
    else:
        i += 1

print(i)
