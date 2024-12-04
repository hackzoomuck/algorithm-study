def solution(skill, skill_trees):
    answer = 0
    skill_dic = {}
    # dic 에 skill을 key로 넣고 순서를 value로 넣는다.
    for idx in range(len(skill)):
        skill_dic[skill[idx]] = idx+1

    # 2 for closure
    for idx1 in skill_trees:
        check = 0
        for id
        x2 in range(len(idx1)):
            if skill_dic.get(idx1[idx2])!=None:
                if skill_dic[idx1[idx2]]-check <= 1:
                    check = skill_dic[idx1[idx2]]
                else:
                    break
            if idx2 == len(idx1)-1:
                answer += 1

    return answer
