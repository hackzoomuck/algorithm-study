// 연속된 부분 최대합 
import sys

def getSubsum(data) :
    '''
    n개의 숫자가 list로 주어질 때, 그 연속 부분 최대합을 반환하는 함수를 작성하세요.
    '''
    max_num = -100000
    for idx, a1 in enumerate(data):
        d = data[idx+1:]
        sum_num = a1
        if max_num < sum_num :
            max_num = sum_num
        for a2 in d: 
            sum_num += a2
            if max_num < sum_num:
                max_num = sum_num

    return max_num

def main():

    data = [int(x) for x in input().split()]

    print(getSubsum(data))

if __name__ == "__main__":
    main()
