import sys


input = sys.stdin.readline
G = int(input())
P = int(input())

parent = [i for i in range(G + 1)]
res = 0
for _ in range(P):
    plane = int(input())

    gate = plane
    while parent[gate] != gate:
        gate = parent[gate]
    if gate == 0:
        break
    else:
        parent[gate] = gate - 1
        parent[plane] = parent[gate]
        res += 1
print(res)
