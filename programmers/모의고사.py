def solution(answers):
    answer = []
    a1 = [1, 2, 3, 4, 5]
    a2 = [2, 1, 2, 3, 2, 4, 2, 5]
    a3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    cnt = [0]*3
    for i, idx in enumerate(answers):
        if idx == a1[i % 5]:
            cnt[0] += 1
        if idx == a2[i % 8]:
            cnt[1] += 1
        if idx == a3[i % 10]:
            cnt[2] += 1
    return [i+1 for i, v in enumerate(cnt) if v == max(cnt)]

a = [1,3,2,4,2]
print(solution(a))
