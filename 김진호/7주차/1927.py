import sys, heapq

input = sys.stdin.readline
N = int(input())

pq = []
for _ in range(N):
    num = int(input())

    if num == 0:
        print(heapq.heappop(pq) if len(pq) != 0 else 0)
    else:
        heapq.heappush(pq, num)