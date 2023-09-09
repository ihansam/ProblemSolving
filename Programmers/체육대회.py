ans, dep = 0, 0
vis, ab = [], []


def back_track(d, sc):
    global ans, dep, vis, ab
    if d == dep:
        if sc > ans:
            ans = sc
        return

    for i in range(len(vis)):
        if vis[i]:
            continue
        vis[i] = 1
        back_track(d + 1, sc + ab[i][d])
        vis[i] = 0


# 5.7s
def solution_bt(ability):
    global ans, dep, vis, ab
    ans, dep = 0, len(ability[0])
    vis = [0] * len(ability)
    ab = ability
    back_track(0, 0)
    return ans


from itertools import permutations as p


# 5.8s
def solution_permutation(ability):
    answer = 0
    n, r = len(ability), len(ability[0])
    for idx in p(range(n), r):
        score = sum(ability[i][j] for j, i in enumerate(idx))
        answer = max(answer, score)

    return answer

