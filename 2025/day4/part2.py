def main():
    arr = []
    accessible = 0

    with open("input.txt", "r") as file:
        for line in file:
            line = line.strip()

            row = []

            for i in range(len(line)):
                row.append(line[i])

            arr.append(row)

        rows = len(arr)
        cols = len(arr[0])

        for r in range(rows):
            for c in range(cols):
                adjacent = 0;

                # print(f"ARR[r][c] = ARR[{r}][{c}]")
                if (arr[r][c] == "."): continue

                for i in range(r-1, r+2):
                    if (i < 0 or i >= rows): continue

                    for j in range(c-1, c+2):
                        if (j < 0 or j >= cols): continue
                        elif (i == r and j == c): continue
                        else:
                            # print(f"arr[{i}][{j}] = {arr[i][j]}")
                            if (arr[i][j] == '@'):
                                adjacent += 1
                                # print(f"adjacent = {adjacent}")
                            # else:
                                # print("skip")

                if (adjacent < 4):
                    accessible += 1
                    # print(f"adding to accessible, {accessible}")
                # print("")

    print("Accessible: ", accessible)


if __name__ == "__main__":
    main()
