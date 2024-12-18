FILE = 'input.txt'

with open(FILE, 'r') as file:
    count = 0

    for line in file:
        line = list(map(int, line.strip().split(' ')))
        condition1 = True
        condition2 = True
        dampener = False
        i = 0

        while i < len(line) - 1:
            if not line[0] == line[1]:
                INC = line[0] < line[1]
            else:
                line.pop(0)
                dampener = True
                INC = line[0] < line[1]

            # Check first condition
            if INC and line[i] >= line[i+1] or not INC and line[i] <= line[i+1]:
                if not dampener:
                    line.pop(i+1)
                    dampener = True
                    i = 0
                    INC = line[0] < line[1]
                    continue
                else:
                    condition1 = False
                    break

            # Check second condition
            if abs(line[i]-line[i+1]) > 3:
                if not dampener:
                    line.pop(i+1)
                    dampener = True
                    i = 0
                    continue
                else:
                    condition2 = False
                    break

            i += 1
        
        if condition1 and condition2:
            count += 1
        else:
            print(line)

    print(count)
