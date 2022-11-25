import sys, heapq 
N = int(sys.stdin.readline())
heap = []
for i in range(N):
    num = map(int,sys.stdin.readline().split())
    for j in num:
        if len(heap) < N:
            heapq.heappush(heap,j)
        else:
            if j > heap[0]:
                heapq.heappop(heap)
                heapq.heappush(heap, j)
print(heap[0])
