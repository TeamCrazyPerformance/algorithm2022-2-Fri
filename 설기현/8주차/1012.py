## 1012  유기농 배추  
import sys 
sys.setrecursionlimit(10**9) 
input = sys.stdin.readline


def dfs(x,y):
    # if x >= 0 and x < N and y >= 0 and y < M:     # x -> M    ,  y -> N 
    #     return True  
    if x <= -1 or x >= N or y <= -1 or y >= M:
        return False
    if ground[x][y] ==1:
        ground[x][y] = 0 
        dfs(x-1,y)
        dfs(x,y-1)
        dfs(x+1,y)
        dfs(x,y+1)
        return True
    return False
    
for i in range(int(input())):
    M, N, K = map(int, input().split())
    ground = [[0]*M for i in range(N)]
    cnt = 0
    for i in range(K):
        x,y = map(int, input().split())
        ground[y][x] = 1             # 틀린 부분.x,y반대로 적지 않도록 주의. 가로가 x -> M, 세로가 y -> N
        
    for i in range(N):
        for j in range(M):
            if ground[i][j] == 1:
                dfs(i,j)
                cnt += 1
    print(cnt)  
