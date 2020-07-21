
def findnext(curr, grp, visit):
    for node in grp[curr]:
        if visit[node] == 0:
            return node
    return 0

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    V, E = map(int, input().split())
    GRAPH = {i: [] for i in range (1, V+1)}
    for i in range(E):
        Parent, Child = map(int, input().split())
        GRAPH[Parent].append(Child)
    S, G = map(int, input().split())
    VISIT = [0 for _ in range(V+1)]
    pathfound = 0
    STACK = [0]

    curr = S
    VISIT[curr] = 1
    while curr:
        next = findnext(curr, GRAPH, VISIT)
        while next:            
            if next == G:
                pathfound = 1
                #print(STACK, curr, G)
                break        
            STACK.append(curr)
            VISIT[next] = 1
            curr = next
            next = findnext(curr, GRAPH, VISIT)
        curr = STACK.pop()

    print("#%d %d" %(test_case, pathfound))
