
## 2178번 미로탐색 dfs방식 -----가능한 최대 깊이로 지점들을 탐색하는 방식이기 때문에 최소값을 찾는 방식과 거리가 멀다. 실패. 
import sys 
sys.setrecursionlimit(10**9)
# from collections import deque
input = sys.stdin.readline

def dfs(x, y):                           #세로: 0 <= x < N  가로: 0 <= y < M
    global cnt 
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    for i in range(4):
        xi = x + dx[i]
        yi = y + dy[i]
    
        # if (0 <= xi < N) and (0 <= yi < M):
        if not (xi < 0 or xi >= N or yi < 0 or yi >= M):
            if maze[xi][yi] == 1 and visited[xi][yi] == 0:
                maze[xi][yi] = 0
                visited[xi][yi] = 1
                cnt += 1
                dfs(xi, yi)
                if xi == N-1 and yi == M-1: 
                    print(cnt)
                  

N, M = map(int, input().split())
maze = []
for i in range(N):
    maze.append(list(map(int, input().strip()))) # 공백 제거 해줘야. readline의 경우 개행문자를 입력받기 때문. 
# print(lst)
visited = [[0]*M for i in range(N)]
cnt = 0

dfs(0,0)











## 2178번 미로탐색 bfs방식 -----
import sys 
# sys.setrecursionlimit(10**9)
from collections import deque
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x, y):                           #세로: 0 <= x < N  가로: 0 <= y < M
    q = deque()     #([x,y])
    q.append([x,y])
    # q.append((x,y))
    # print(q)
    while q:
        x,y = q.popleft()    #q.pop(0)
       
        for i in range(4):
            xi = x + dx[i]
            yi = y + dy[i]
            if not (xi < 0 or xi >= N or yi < 0 or yi >= M):   # if (0 <= xi < N) and (0 <= yi < M):
                if maze[xi][yi] == 1 and visited[xi][yi] == 0:
                    q.append([xi,yi])
                    maze[xi][yi] = maze[x][y]+1
                    visited[xi][yi] = 0 
    print(maze[N-1][M-1])
  

N, M = map(int, input().split())
maze = []
for i in range(N):
    maze.append(list(map(int, input().strip()))) # 공백 제거 해줘야. readline의 경우 개행문자를 입력받기 때문. 
# print(lst)
visited = [[0]*M for i in range(N)]

bfs(0,0)

