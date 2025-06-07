matrix = []
count = 0

with open('input.txt', 'r') as file:
    for line in file:
        matrix.append(list(line.strip()))

for col in range(len(matrix) - 2):
    for row in range(len(matrix[0]) - 2):
        word1 = matrix[col][row] + matrix[col+1][row+1] + matrix[col+2][row+2]
        word2 = matrix[col][row+2] + matrix[col+1][row+1] + matrix[col+2][row]

        if (word1 == 'MAS' or word1[::-1] == 'MAS') and (word2 == 'MAS' or word2[::-1] == 'MAS'):
            count +=1

print(count)
