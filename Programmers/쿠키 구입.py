# 384ms
def solution(cookie):
    if len(cookie) == 1:
        return 0
    
    ans = 0

    for m in range(len(cookie)-1):
        i, j = m, m+1
        ls, rs = cookie[i], cookie[j]
        while True:
            if ls == rs:
                ans = max(ans, ls)
                i -= 1
                j += 1
                if i<0 or j>=len(cookie):
                    break                
                ls += cookie[i]
                rs += cookie[j]
            elif ls > rs:
                j += 1
                if i<0 or j>=len(cookie):
                    break                
                rs += cookie[j]
            else:
                i -= 1
                if i<0 or j>=len(cookie):
                    break                
                ls += cookie[i]
                            
    return ans
