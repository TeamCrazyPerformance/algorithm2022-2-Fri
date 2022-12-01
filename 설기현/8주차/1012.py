## 1012  유기농 배추  
import sys 
sys.setrecursionlimit(10**9) 
input = sys.stdin.readline

def dfs(x,y):
    # if x >= 0 and x < N and y >= 0 and y < M:     
    #     return True  
    if x <= -1 or x >= N or y <= -1 or y >= M:    #세로: 0 <= x < N  가로: 0 <= y < M
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
        ground[y][x] = 1             #세로: 0 <= y < N  가로: 0 <= x < M
        
    for i in range(N):  # 행
        for j in range(M): # 열
            if ground[i][j] == 1:
                dfs(i,j)
                cnt += 1
    print(cnt)  
    
    
    
    
    ------------------------------------------------------------------------------------------------------------------------------------------------------
    
    
    
##sol2) 
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def dfs(x, y):                           #세로: 0 <= x < N  가로: 0 <= y < M
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    for i in range(4):
        xi = x + dx[i]
        yi = y + dy[i]
    
        # if (0 <= xi < N) and (0 <= yi < M):
        if not (xi < 0 or xi >= N or yi < 0 or yi >= M):
            if ground[xi][yi] == 1:
                ground[xi][yi] = 0
                dfs(xi, yi)


T = int(input())
for _ in range(T):
    M, N, K = map(int, input().split())          
    ground = [[0]*M for _ in range(N)]       
    cnt = 0
    
    for _ in range(K):
        x, y = map(int, input().split())
        ground[y][x] = 1                        #세로: 0 <= y < N  가로: 0 <= x < M

    for i in range(N):  # 행 
        for j in range(M):  # 열 
            if ground[i][j] == 1:
                dfs(i, j)
                cnt += 1

    print(cnt)
