matrix = []
count = 0

with open('input.txt', 'r') as file:
    for line in file:
        matrix.append(list(line.strip()))

for col in range(len(matrix)):
    for row in range(len(matrix[0])):

        # match horizontal and reverse
        if row < len(matrix[0]) - 3:
            word = matrix[col][row] + matrix[col][row+1] + matrix[col][row+2] + matrix[col][row+3]
            if word == 'XMAS' or word[::-1] == 'XMAS':
                count += 1

        # match vertical and reverse
        if col < len(matrix) - 3:
            word = matrix[col][row] + matrix[col+1][row] + matrix[col+2][row] + matrix[col+3][row]
            if word == 'XMAS' or word[::-1] == 'XMAS':
                count += 1

        # match l-r diagonal and reverse
        if col < len(matrix) - 3 and row < len(matrix[0]) - 3:
            word = matrix[col][row] + matrix[col+1][row+1] + matrix[col+2][row+2] + matrix[col+3][row+3]
            if word == 'XMAS' or word[::-1] == 'XMAS':
                count += 1

        # match r-l diagonal and reverse
        if col < len(matrix) - 3 and row < len(matrix[0]) - 3:
            word = matrix[col][row+3] + matrix[col+1][row+2] + matrix[col+2][row+1] + matrix[col+3][row]
            if word == 'XMAS' or word[::-1] == 'XMAS':
                count += 1

print(count)
