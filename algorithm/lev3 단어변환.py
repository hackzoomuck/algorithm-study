# bfs 로 풀어서 깊이 잼.
# 같은 깊이에는 부모와 한글자 다른 단어가 큐에 들어가게 됨. (한 글자 차이 나는 것을 비교하는 것은 어떻게 할까유?=>16줄)
def solution(begin, target, words):
    height = 0
    qu = [[begin, 0]]
    check = False
    while qu:
        now_node = qu[0]
        qu.pop(0)
        if now_node[0] == target:
            height = now_node[1]
            check = True
            break
        index = 0
        while index is not len(words):
            if [words[index][i] == now_node[0][i] for i in range(len(target))].count(False) < 2:
                qu.append([words[index], now_node[1]+1])
                words.pop(index)
            else:
                index +=1
                print('else',index)

    if check is True:
        return height
    return 0
