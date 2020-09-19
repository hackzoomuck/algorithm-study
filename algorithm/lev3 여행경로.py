def dfs(tic, next_jo, ans):
    if len(ans) == a:
        global answer
        answer = ans
        return answer
    for idx, ti in enumerate(tic):
        if ti[0] == next_jo:
            ans.append(ti[1])
            tic.pop(idx)
            dfs(tic, ti[1], ans)
            idx -= 1


def solution(tickets):
    global a
    a = len(tickets) + 1
    tickets.sort()
    start = 'ICN'
    if len(tickets) == 1:
        return tickets
    for idx, value in enumerate(tickets):
        if value[0] == start:
            tic = tickets
            tic.pop(idx)
            answ = [value[0], value[1]]
            dfs(tic, value[1], answ)

            if answer:
                if len(answer) == len(tickets):
                    return answer
    return answer


if __name__ == '__main__':
    begin =	[['ICN','A'],['ICN','A'],['A','ICN']]
