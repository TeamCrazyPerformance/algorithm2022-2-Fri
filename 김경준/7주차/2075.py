import sys, heapq

input = sys.stdin.readline
heap = []

for _ in range(int(input())):
    arr = list(map(int, input().split()))
    if not heap:
        for a in arr:
            heapq.heappush(heap, a)
    else:
        for a in arr:
            if heap[0] < a:
                heapq.heappush(heap, a)
                heapq.heappop(heap)

print(heap[0])
