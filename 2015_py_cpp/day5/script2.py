FILE = 'input.txt'
count = 0

with open(FILE, 'r') as file:
    for line in file:
        condition1 = False
        condition2 = False

        for i in range (0, len(line)-4):
            for j in range(i+2, len(line)-2):
                stringA = line[i] + line[i+1]
                stringB = line[j] + line[j+1]

                if (stringA == stringB):
                    condition1 = True

                if line[i] == line[j]:
                    condition2 = True

                if i == len(line)-5:
                    if line[i+1] == line[j+1]:
                        condition2 = True

        if condition1 and condition2: 
            count += 1

    print(count)
