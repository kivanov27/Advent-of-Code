with open('input.txt', 'r') as file:
    santa_x, santa_y = 0, 0
    robo_x, robo_y = 0, 0
    presents = {}
    presents[0, 0] = 2
    santa = True

    for char in file.read():
        if santa == True:
            if char == '^': santa_y += 1
            elif char == 'v': santa_y -= 1
            elif char == '>': santa_x += 1
            elif char == '<': santa_x -= 1

            if (santa_x, santa_y) not in presents: 
                presents[santa_x, santa_y] = 1
            else:
                presents[santa_x, santa_y] += 1
            santa = False
        else:
            if char == '^': robo_y += 1
            elif char == 'v': robo_y -= 1
            elif char == '>': robo_x += 1
            elif char == '<': robo_x -= 1

            if (robo_x, robo_y) not in presents: 
                presents[robo_x, robo_y] = 1
            else:
                presents[robo_x, robo_y] += 1
            santa = True

    count = sum(1 for value in presents.values() if value >= 1)
    print("Number of houses with presents:", count)
