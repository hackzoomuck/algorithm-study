#최대공약수 찾기
from math import gcd

def solution(w,h):
    gcd_wh = gcd(w,h)
    answer = w*h - (int(w/gcd_wh)-1 + int(h/gcd_wh)-1 +1)*gcd_wh    
    return answer
    
