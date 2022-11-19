import sys
import heapq

numbers = int(input()) #숫자입력
heap = [] #힙

#Max Heap
for _ in range(numbers):
    num = int(sys.stdin.readline()) #숫자입력
    if num != 0: #0아니면 heap에 push해줌
        heapq.heappush(heap, num)
    else:
        try:
            print(heapq.heappop(heap))
        except:
            print(0)
