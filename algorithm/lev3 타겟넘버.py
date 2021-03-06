cnt = 0

# 주어진 배열, 현재 인덱스, target, now_value
def dfs(numbers, start_idx, target, now_value):
    global cnt
    if start_idx == len(numbers):
        if now_value == target:
            cnt += 1
    else:
        dfs(numbers, start_idx+1, target, now_value+numbers[start_idx])
        dfs(numbers, start_idx+1, target, now_value-numbers[start_idx])

    return cnt

def solution(numbers, target):
    answer = dfs(numbers, 0, target, 0)
    return answer
