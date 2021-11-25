def longest(lst):   # input: interger list
    head, tail, sidx = 0, 0, 0
    prev = lst[0]
    for cidx in range(1, len(lst)):
        curr = lst[cidx]
        if prev <= curr:
            pass
        elif (tail-head) < (cidx-sidx):
            head = sidx
            tail = cidx
            sidx = cidx
        else:
            sidx = cidx
        prev = curr
    if (cidx - sidx) > (head - tail):
        head = sidx
        tail = cidx
    return lst[head:tail]


print(longest([1,2,3,4,5,2,3,4,5,5,5,5,2,1,3,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3]))
