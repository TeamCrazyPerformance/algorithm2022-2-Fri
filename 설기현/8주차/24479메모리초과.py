# 메모리초과 
import sys
sys.setrecursionlimit(10**9) 
N, M, R = map(int, sys.stdin.readline().split())

undirected_graph = [[]for i in range(N+1)]  # 0index이므로 N+1\
visited = [0]*(N+1)                         # 방문한 노드 표시하기 위해 
for i in range(M):
    u, v = map(int, sys.stdin.readline().split()) 
    undirected_graph[u].append(v)
    undirected_graph[v].append(u)
    undirected_graph[u].sort()

def dfs(R,cnt):
    visited[R] = cnt 
    for i in undirected_graph[R]:
        if visited[i] ==0:
            cnt += 1
            dfs(i,cnt)

cnt = 1
dfs(R,cnt)

for i in range(1,N+1):
    print(visited[i])

    
'''기존 반례 돌려도 3%오류 해결 안되시는분들 참고하세요^^

6 4 1

2 3

1 4

1 5

4 6

정답

1
0
0
2
4
3

오답 
1
0
0
2
3
3
'''
