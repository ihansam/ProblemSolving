from itertools import permutations as p
from itertools import combinations as c
from itertools import product as pi
from itertools import combinations_with_replacement as h

n, m = map(int, input().split())

ans_perm = list(p(range(1, n+1), m))
ans_comb = list(c(range(1, n+1), m))
ans_rep_perm = list(pi(range(1, n+1), repeat=m))
ans_rep_comb = list(h(range(1, n+1), m))

res_perm, res_comb, res_rep_perm, res_rep_comb = [], [], [], []
visit = [0] * (n+1)
arr = [0] * n


def bt_p(d):
    if d == m:
        res_perm.append(tuple(arr[:m]))
        return
    for i in range(1, n+1):
        if visit[i]:
            continue
        arr[d] = i
        visit[i] = 1
        bt_p(d + 1)
        visit[i] = 0


def bt_c(d, last):
    if d == m:
        res_comb.append(tuple(arr[:m]))
        return
    for i in range(last+1, n+1):
        arr[d] = i
        bt_c(d+1, i)


def bt_rp(d):
    if d == m:
        res_rep_perm.append(tuple(arr[:m]))
        return
    for i in range(1, n+1):
        arr[d] = i
        bt_rp(d+1)


def bt_rc(d, last):
    if d == m:
        res_rep_comb.append(tuple(arr[:m]))
        return
    for i in range(last, n+1):
        arr[d] = i
        bt_rc(d+1, i)


bt_p(0)
bt_c(0, 0)
bt_rp(0)
bt_rc(0, 1)


assert res_perm == ans_perm
assert res_comb == ans_comb
assert res_rep_perm == ans_rep_perm
assert res_rep_comb == ans_rep_comb
