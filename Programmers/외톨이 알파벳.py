from collections import Counter


def solution(input_string):
    merged = [""]

    for s in input_string:
        if s == merged[-1]:
            continue
        merged.append(s)

    c = Counter(merged[1:])
    ans = [k for k, v in c.items() if v > 1]

    return ''.join(sorted(ans)) or 'N'
