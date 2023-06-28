import sys

inp = sys.stdin.readline


class Trie:
    def __init__(self):
        self.root = {}
    
    def insert(self, string):
        node = self.root
        for s in string:
            if '_' in node.keys():
                return False
            if s not in node.keys():
                node[s] = {}
            node = node[s]
        node['_'] = 'END'
        return True

    def __str__(self):
        return str(self.root)


# main
answer = []

for _ in range(int(inp())):
    book = [inp().strip() for _ in range(int(inp()))]
    book.sort()
    trie = Trie()
    ret = True
    for num in book:
        if not trie.insert(num):
            ret = False
            break
    answer.append("YES" if ret else "NO")

print('\n'.join(answer))
