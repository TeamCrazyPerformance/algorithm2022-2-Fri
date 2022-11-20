import sys, heapq

input = sys.stdin.readline

N = int(input())

arr = []
for _ in range(N):
    for num in list(map(int, input().split())):
        if len(arr) < N:
            heapq.heappush(arr, num)
        elif arr[0] < num:
            heapq.heappop(arr)
            heapq.heappush(arr, num)
print(arr[0])