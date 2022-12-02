# 24444 알고리즘 수업 - 너비 우선 탐색 1  - per1
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



def bfs(R):
    global cnt 
    q = deque([R])
    visited[R] = cnt     
    while q:
        ql = q.popleft()
        undirected_graph[ql].sort()
        for i in undirected_graph[ql]:
            if visited[i] == 0:
                cnt+=1
                visited[i] = cnt
                q.append(i)
    print(*visited[1:], sep="\n")



bfs(R) 






























# 24444 알고리즘 수업 - 너비 우선 탐색 1 -per2
#Python에서 Queue 자료구조는 Stack과 Queue를 합친 Deque을 사용. collections 라이브러리의 deque(double-ended queue의 약자)
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
    ql = q.popleft()    # 가장 앞(front)의 pop은 popleft(queue로 동작) 그리고 가장 오른쪽(상위-rear) pop은 pop(stack처럼 동작) 연산을 사용.
    undirected_graph[ql].sort()
    for i in undirected_graph[ql]:
        if visited[i] == 0:
            cnt+=1
            visited[i] = cnt
            q.append(i)
     
for i in range(1,N+1):
    print(visited[i])
    
     
