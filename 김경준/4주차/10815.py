#이진탐색 10815
n = int(input())
a = list(map(int, input().split()))
a.sort()

def binary_search(num):
    l = 0
    r = n-1
    while l <= r :
        mid = (l+r)//2
        if a[mid] == num :
            return 1
        elif a[mid] > num :
            r = mid - 1
            # 반 줄여주기 1
        else:
            l = mid + 1
            # 반 줄여주기 2
    return 0

input()
for num in list(map(int, input().split())):
    print(binary_search(num), end = ' ')
    
    
#시간초과 뜸
#10815
input()
n=list(map(int,input().split())) #갖고있는 카드 숫자 입력받기
#print(n)
input()
m=list(map(int,input().split())) #카드 숫자 입력받기
for i in m:
    if i in n:
        print(1,end=" ")
    else:
        print(0, end=" ")
