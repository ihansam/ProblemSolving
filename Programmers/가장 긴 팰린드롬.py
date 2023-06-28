# 354ms
def solution(s):
    answer = 1
    n = len(s)
    
    for i in range(n-1):
        # odd
        d = 1
        while (0<=i-d<n) and (0<=i+d<n) and (s[i-d]==s[i+d]):
            d += 1
        answer = max(answer, 2*d-1)
    
        # even
        d = 0
        while (0<=i-d<n) and (0<=i+d+1<n) and (s[i-d]==s[i+d+1]):
            d += 1
        answer = max(answer, 2*d)
    
    return answer


# 1020ms??
def solution(s):
    string = f"!{'!'.join(list(s))}!"
    n = len(string)
    
    pldr = [0] * n
    c, r = 0, 0
    
    for i in range(n):
        if i <= r:
            d = min(pldr[c-(i-c)], r-i)
        
        d = pldr[i]
        while (0 <= i+d+1 < n) and (0 <= i-d-1 < n) and (string[i+d+1] == string[i-d-1]):
            d += 1
        
        pldr[i] = d

    return max(pldr)
