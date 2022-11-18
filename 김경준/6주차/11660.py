#11660

#시간초과
"""
import sys
input = sys.stdin.readline
n, m = map(int, input().split())

arr = []

for i in range(n):
    a = list(map(int, input().split()))
    arr.append(a)
    
def sum_arr(x1, y1, x2, y2):
    sum = 0
    for row in range(x1-1, x2):
        for col in range(y1-1, y2):
            sum += arr[row][col]
    return sum
            
for i in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    result = sum_arr(x1, y1, x2, y2)
    print(result)
"""