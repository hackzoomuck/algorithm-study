def solution(m, n, board):
    answer = 0
    dx = [0, 1, 1]
    dy = [1, 0, 1]
    check = True
    tmp = board
    board = []
    for b in range(len(tmp)):
        board.append(list(tmp[b].strip()))
    findloc = []
    while check:
        findloc.clear()
        for x in range(m-1):
            for y in range(n-1):
                cnt = 0
                print('x:', x,' y:', y)
                if board[x][y] == ' ':
                    print('board[x][y] is '' ')
                    continue

                for t in range(3):
                    print('t:', t)
                    if board[x][y] == board[x+dx[t]][y+dy[t]]:
                        cnt += 1
                    else:
                        break

                print('cnt:', cnt)
                if cnt == 3:
                    findloc.append([x, y])
                    
        if len(findloc):
            for f in range(len(findloc)):
                board[findloc[f][0]][findloc[f][1]] = 'x'
                board[findloc[f][0]+dx[0]][findloc[f][1]+dy[0]] = 'x'
                board[findloc[f][0]+dx[1]][findloc[f][1]+dy[1]] = 'x'
                board[findloc[f][0]+dx[2]][findloc[f][1]+dy[2]] = 'x'


            for x1 in range(m):
                for y1 in range(n):
                    if board[x1][y1] == 'x':
                        answer += 1
                        for x2 in range(x1, -1, -1):
                            print('x2:',x2, 'y1', y1)
                            if x2 == 0:
                                board[x2][y1] = ' '
                            else:
                                #print('board[x2][y1]',board[x2][y1], board[x2-1][y1])
                                board[x2][y1] = board[x2-1][y1]
                                #print('board[x2][y1]',board[x2][y1])
                                board[x2 - 1][y1] = ' '
            for x2 in range(m):
                print(board[x2])

        else:
            check=False

    return answer


b = ["AAAAAA", "BBAATB", "BBAATB", "JJJTAA", "JJJTAA"]
print(solution(5,6,b))
