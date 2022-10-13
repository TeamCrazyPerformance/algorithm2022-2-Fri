import sys


def find(x):
    if x == parent[x]:
        return x
    parent[x] = find(parent[x])
    return parent[x]


sys.setrecursionlimit(100000)
input = sys.stdin.readline
G = int(input())
P = int(input())

parent = [i for i in range(G + 1)]
res = 0
for _ in range(P):
    plane = int(input())

    gate = find(plane)
    if gate == 0:
        break
    else:
        parent[gate] = gate - 1
        res += 1
print(res)
