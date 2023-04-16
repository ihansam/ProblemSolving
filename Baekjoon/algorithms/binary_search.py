# hash 쓰는 게 더 빠르긴 함
# boj 1920
import bisect
import sys

inp = sys.stdin.readline
n, arr = int(inp()), list(map(int, inp().split()))
m, nums = int(inp()), map(int, inp().split())
arr.sort()


def _bis(t):
    l = bisect.bisect_left(arr, t)
    r = bisect.bisect_right(arr, t)
    print(1 if r-l else 0)


def bis(t):
    s, e = 0, n-1
    while s <= e:
        mid = (s+e)//2
        curr = arr[mid]
        if curr == t:
            print(1)
            return
        elif curr > t:
            e = mid - 1
        else:
            s = mid + 1
    print(0)


for _t in nums:
    _bis(_t)




# def rec_bis(s, e, t):
#     if s == e:
#         print(int(arr[s] == t))
#         return
#     mid = (s+e)//2
#     if arr[mid] < t:
#         rec_bis(mid+1, e, t)
#     else:
#         rec_bis(s, mid, t)


# for t in nums:
#     rec_bis(0, m-1, t)
