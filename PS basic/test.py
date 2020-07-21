import sys
sys.stdin = open("input.txt", "r")

def pairs(n):
    for i in range(n):
        for j in range(n):
            yield i, j

move = [(0,0), (0, -1), (-1, 0), (1, 0), (0, 1)]    # direction to stay, left, up, down, right correspond to 0 to 4 

def findPath(map, currpos, pastmove, N):    # 최종 종착지 도달 여부 FOUND 및 다음으로 이동 가능한 방향 및 위치를 찾는 함수
    FOUND = False
    CanMovePositions = []                           # list of [direction, nextposition]
    for direction in range(1, 5):
        if direction + pastmove == 5:               # 다시 되돌아가지 않는다. (이전 방향과 index합이 5인 경우)
            continue
        cango, nextpos = movement(currpos, N, direction)
        if not cango:
            continue
        nextPosVal = map[nextpos[0]][nextpos[1]]    # 다음 위치에 대한 map의 값
        if nextPosVal == 1:
            continue
        elif nextPosVal == 3:                       # 다음 위치가 종착지면 다른 경로를 지우고 종착지로 향한다
            FOUND = True
            CanMovePositions.clear()
            CanMovePositions.append([direction, nextpos])
            return FOUND, CanMovePositions
        elif nextPosVal == 0:                       # 갈 수 있는 방향 및 위치를 리턴할 리스트에 추가한다
            CanMovePositions.append([direction, nextpos])

    return FOUND, CanMovePositions

def movement(position, N, direction):       # position을 direction방향으로 이동시킬 수 있는지 여부와 이동된 위치를 반환하는 함수
    global move
    row = position[0]
    col = position[1]
    row += move[direction][0]
    col += move[direction][1]
    if (row >= N) or (row < 0) or (col >= N) or (col < 0):      # 이동 가능 범위 초과
        return False, position
    else:
        return True, [row, col]

def Search(map, currPos, pastDirection, N, done):
    if done:
        return 1
    print(pastDirection, currPos)
    EXIT, nextPosCandidates = findPath(map, currPos, pastDirection, N)
    if EXIT:
        return 1
    elif len(nextPosCandidates) != 0:
        for d, pos in nextPosCandidates:
            done = Search(map, pos, d, N, done)
            return done
    return 0

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):

    N = int(input())
    miro = [list(map(int, input())) for i in range(N)]

    for i, j in pairs(N):           # find start position
        if miro[i][j] == 2:
            break                                                   # stay, left, up, down, right    
    startPos = [i, j]

    EXIT = False
    EXIT = Search(miro, startPos, 0, N, EXIT)

    print("#%d %d" %(test_case, EXIT))
