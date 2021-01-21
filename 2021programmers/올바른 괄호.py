def solution(s):
    answer = True
    left = 0
    for i in range(len(s)):
        if s[i] == '(':
            left += 1
        else:
            if left < 1:
                 return False
            else:
                left -= 1
    if left > 0:
        return False
    return True
