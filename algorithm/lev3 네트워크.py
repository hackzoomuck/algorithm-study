def solution(n, computers):
    answer = 0
    cnt = 0
    visited = [0]*n
    def dfs(c):
        visited[c] = 1
        for s in range(n):
            if visited[s] is not 1 and computers[c][s] is 1:
                dfs(s)
    for i in computers:
        if visited[cnt] is not 1:
            dfs(cnt)
            answer+=1
        cnt+=1
    return answer
