import sys
from collections import deque

input = sys.stdin.readline

N, M, R = map(int, input().split())

graph = {i: [] for i in range(1, N + 1)}
res = [0] * (N + 1)

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

for v in graph.values():
    v.sort()


def bfs(n):
    cnt = 1
    q = deque([n])

    while q:
        v = q.popleft()
        if res[v] != 0:
            continue
        res[v] = cnt
        cnt += 1

        for i in graph[v]:
            if res[i] == 0:
                q.append(i)


bfs(R)

print(*res[1:], sep="\n")
