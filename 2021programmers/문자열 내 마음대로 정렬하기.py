def solution(strings, n):
    answer = []
    for s in strings:
        for idx, a in enumerate(answer):
            if a[n] == s[n]:
                if a > s:
                    answer.insert(idx,s)
                    break
            elif a[n] > s[n]:
                answer.insert(idx, s)
                break
            # last line
            if idx == len(answer)-1:
                answer.append(s)
                break
        if len(answer) == 0:
            answer.append(s)
    return answer
