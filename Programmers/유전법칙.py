def find(gen, th):
    if gen == 1:
        return "Rr"

    index = []

    for g in range(gen, 2, -1):
        index.append(th % 4)
        th //= 4
    index.append(th)

    for idx in index[::-1]:
        if idx == 0:
            return 'RR'
        if idx == 3:
            return 'rr'
    return 'Rr'


def solution(queries):
    return [find(g, th - 1) for g, th in queries]
