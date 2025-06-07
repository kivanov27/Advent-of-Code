with open('input.txt', 'r') as file:
    lines = file.readlines()

rules = []
pageUpdates = []
switch = False

for line in lines:
    line = line.strip()

    if not line:
        switch = True
        continue

    if not switch:
        rules.append(list(map(int, line.split('|'))))
    else:
        pageUpdates.append(list(map(int, line.split(','))))

for update in pageUpdates:
    correct = False

    for rule in rules:
        rule0found = False
        rule1found = False

        for page in update:
            if page == rule[0] and not rule1found:
                rule0found = True
            elif page == rule[1] and rule0found:
                correct = True
