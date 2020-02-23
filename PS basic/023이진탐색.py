T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    P, A, B = map(int, input().split())
    la, lb = 1, 1
    ra, rb = P, P
    atry, btry = 0, 0
    while (ra-la)>0:
        atry += 1
        ca = int((ra+la)/2)
        if A == ra and (ra-la) == 1:
            break
        if A == ca:
            break
        elif A<ca:
            ra = ca
        else:
            la = ca
    while (rb-lb)>0:
        btry += 1
        cb = int((rb+lb)/2)
        if B == rb and (rb-lb) == 1:
            break
        if B == cb:
            break
        elif B<cb:
            rb = cb
        else:
            lb = cb
    res = ""
    if atry<btry:
        res = "A"
    elif atry == btry:
        res = "0"
    else:
        res = "B"

    print("#%d %s" %(test_case, res))
