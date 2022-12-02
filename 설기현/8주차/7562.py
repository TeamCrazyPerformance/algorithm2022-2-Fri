#7562 나이트의 이동- bfs 
import sys 
# sys.setrecursionlimit(10**9)
from collections import deque
input = sys.stdin.readline

dx = [-1,1,2,2,1,-1,-2,-2]
dy = [2,2,1,-1,-2,-2,-1,1]

def bfs(xs,ys,xe,ye):                           #세로: 0 <= x < N  가로: 0 <= y < M
    q = deque()     
    q.append([xs,ys])  # q.append((x,y)) 역시 동일 
    # print(q)
    if xs == xe and ys == ye: 
        print(0)
    else:     
        while q:
            xs,ys = q.popleft()    #q.pop(0)
            for i in range(8):
                xi = xs + dx[i]
                yi = ys + dy[i]
                if (0 <= xi < n) and (0 <= yi < n) and board[xi][yi]==0:     # if not (xi < 0 or xi >= n or yi < 0 or yi >= n):   
                        q.append([xi,yi])
                        board[xi][yi] = board[xs][ys]+1 
        print(board[xe][ye])
  

for i in range(int(input())):
    n = int(input())
    xs, ys = map(int, input().split())
    xe, ye = map(int, input().split())
    board = [[0]*n for i in range(n)]
    bfs(xs,ys,xe,ye)
