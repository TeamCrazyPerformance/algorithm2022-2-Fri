import sys, heapq

input = sys.stdin.readline

N = int(input())

arr = []
for _ in range(N):
    s, t = map(int, input().split())
    arr.append((s, t))

arr.sort()

rooms = []
for s, t in arr:
    if len(rooms) and s >= rooms[0]:
        heapq.heapreplace(rooms, t)
    else:
        heapq.heappush(rooms, t)

print(len(rooms))