def solution(n):
    answer = 0
    fn = [0,1]
    if n == 1:
        return fn[1]
    for i in range(2,n+1):
        res = fn[i-1] + fn[i-2]
        fn.append(res)
        
    return fn[n]%1234567
