with open('input.txt', 'r') as file:
    paper = 0
    ribbon = 0

    for line in file:
        line = line.strip()

        if not line:
            continue

        l, w, h = map(int, line.split('x'))
        a, b = sorted([l, w, h])[:2]
        
        paper += 2*l*w + 2*w*h + 2*l*h + a*b
        ribbon += l*w*h + 2*a + 2*b

    print('paper:', paper)
    print('ribbon:', ribbon)
