def DFS(map, start, target):
    stack = [start]
    
    while len(stack) > 0:
        node = stack.pop()
        print(node, end="->")
        if node == target:
            print("found")
            return 1
        child = map[node]
        stack.extend(child)
    
    return 0

def BFS(map, start, target):
    queue = [start]

    while len(queue) > 0:
        node = queue.pop(0)
        print(node, end="->")
        if node == target:
            print("found")
            return 1
        child = map[node]
        queue.extend(child)

    return 0

map = {1: [2,3,4], 2: [5], 3: [6], 4: [7,8], 5: [9,10], 6: [], 7: [], 8: [11], 9: [], 10: [], 11: []}
BFS(map, 1, 11)
DFS(map, 1, 11)