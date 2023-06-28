# # 0.16ms
# def solution(skill, skill_trees):
#     answer = 0
#     sk = list(skill)[::-1]
    
#     for st in skill_trees:
#         i, j = -1, 0
#         ban = set(sk[:-1])
#         valid = 1
#         while -i <= len(sk) and j < len(st):
#             s = st[j]
#             if s in ban:    # forbidden skill
#                 valid = 0
#                 break
#             if s == sk[i]:  # get skill
#                 i -= 1
#                 if -i <= len(sk):
#                     ban.discard(sk[i])
#             j += 1
#         answer += valid
    
#     return answer


# 0.02ms
# 스킬셋에 있으면 learn하고, 그 순서가 skill과 일치하면 +1
def solution(skill, skill_trees):
    answer = 0
    skill_set = set(skill)
    
    for skill_tree in skill_trees:
        learned = []
        for s in skill_tree:
            if s in skill_set:
                learned.append(s)
        if ''.join(learned) == skill[:len(learned)]:
            answer += 1

    return answer
