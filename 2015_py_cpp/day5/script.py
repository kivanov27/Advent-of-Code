VOWELS = 'aeiou'
DISALLOWERD = ['ab', 'cd', 'pq', 'xy']
FILE = 'input.txt'
count = 0

with open(FILE, 'r') as file:
    for line in file:
        condition1 = False
        condition2 = False
        condition3 = True
        vowelCount = 0

        for i in range(0, len(line)):
            if not i == len(line)-1:
                j = i+1
                
                # check if this and next char are the same
                if line[i] == line[j]:
                    condition2 = True

                # check if it contains any of the DISALLOWERD strings
                for combo in DISALLOWERD:
                    if '{}{}'.format(line[i],line[j]) == combo:
                        condition3 = False
                        break

            # check if it has 3 VOWELS
            if line[i] in VOWELS:
                vowelCount += 1
                if vowelCount >= 3:
                    condition1 = True

        if condition1 and condition2 and condition3:
            count += 1

    print(count)
