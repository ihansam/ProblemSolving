def DFS(map, start, target):
    stack = [start]
    
    while len(stack) > 0:
        node = stack.pop()
        if node == target:
            return 1
        child = map[node]
        stack.extend(child)
    
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
    
    print("#%d %s" %(test_case, DFS(GRAPH, S, G)))
