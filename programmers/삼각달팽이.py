def solution(n):
    arr_size = int((1+n)*n/2)
    answer = [1 for i in range(arr_size)]

    idx = 0
    num = 2
    for i in range(n):
        if n == 0:
            break
        if i == 0:
            # plus (cnt : n-1): 1, 2, 3,,, n-1
            for i0 in range(1, n, 1):
                idx += i0
                answer[idx] = num
                num += 1
        elif i == 1:
            # plus (cnt : n-1): 1, 1, 1,,, 1
            for i1 in range(1, n):
                idx += 1
                answer[idx] = num
                num += 1
        elif (i + 1)%3 == 0:
            # minus (cnt : n-2): n, n-1, n-2,,,
            a2 = int((i+1)/3-1)
            for i2 in range(n-a2, i-a2, -1):
                idx -= i2
                answer[idx] = num
                num += 1
        elif (i + 1) % 3 == 1:
            a3 = 2
            for i3 in range(i, n):
                idx += a3
                answer[idx] = num
                a3 += 1
                num += 1
        else:
            for i4 in range(i, n):
                idx += 1
                answer[idx] = num
                num += 1


    return answer
