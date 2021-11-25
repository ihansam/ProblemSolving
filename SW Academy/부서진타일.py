T = int(input())

for test_case in range(1, T + 1):
    possible = True
    row, col = map(int, input().split())
    floor = [input() for _ in range(row)]

    for i in range(row-1):
        if possible:
            for j in range(col-1):
                if floor[i][j] == '#':
                    if floor[i][j+1] == '#' and floor[i+1][j:j+2] == "##":
                        floor[i] = floor[i][0:j]+".."+floor[i][j+2:]
                        floor[i+1] = floor[i+1][0:j]+".."+floor[i+1][j+2:]
                    else:
                        possible = False
                        break
        else:
            break

    if possible:
        for i in range(row-1):
            if floor[i][-1] == '#':
                possible = False
                break
    if possible:
        for j in range(col):
            if floor[-1][j] == '#':
                possible = False

    if possible:
        print('#{} YES'.format(test_case))
    else:
        print('#{} NO'.format(test_case))
