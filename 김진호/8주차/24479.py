import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, M, R = map(int, input().split())

graph = {i: [] for i in range(1, N + 1)}
visited = [False for i in range(N + 1)]
res = [0 for _ in range(N + 1)]

for _ in range(M):
    u, v = map(int, input().split())

    graph[u].append(v)
    graph[v].append(u)

for v in graph.values():
    v.sort()

order_num = 1
def dfs(v):
    global order_num
    res[v] = order_num
    order_num += 1
    visited[v] = True

    for i in graph[v]:
        if visited[i] is False:
            dfs(i)

dfs(R)

for i in range(N):
    print(res[i + 1])