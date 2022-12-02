# 24444 알고리즘 수업 - 너비 우선 탐색 1
from collections import deque 
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9) 
N, M, R = map(int, sys.stdin.readline().split())

undirected_graph = [[]for i in range(N+1)]  # 0index이므로 N+1
visited = [0]*(N+1)                         # 방문한 노드 표시하기 위해 

for i in range(M):
    u, v = map(int, sys.stdin.readline().split()) 
    undirected_graph[u].append(v)
    undirected_graph[v].append(u)
cnt = 1 
q = deque([R])
visited[R] = cnt     #R 인덱스 먼저 초기화

while q:
    ql = q.popleft()    # 맨 왼쪽 값 pop시키도록. 
    undirected_graph[ql].sort()
    for i in undirected_graph[ql]:
        if visited[i] == 0:
            cnt+=1
            visited[i] = cnt
            q.append(i)
     
for i in range(1,N+1):
    print(visited[i])
    
     
