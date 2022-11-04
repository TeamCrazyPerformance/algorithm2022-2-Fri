#2805

import sys
input = sys.stdin.readline

n,m=map(int,input().split())
trees=list(map(int,input().split()))
start,end=1,sum(trees)

#start,end가 같아질때 까지
while start<=end:
    mid=(start+end)//2 #중간
    cnt=0
    #나무 자르기
    for tree in trees:
        #나무의 높이가 절단기보다 큰 경우
        if tree > mid:
            #자르기
            cnt +=tree-mid
    #자른 나무들의 길이가 목표값보다 큰 경우
    if cnt >=m:
        #시작위치
        start=mid+1
    #목표값 이하
    else:        
        #끝위치
        end=mid-1
print(end)        


#pypy로 하면 더 빠르게 통과됨
#PyPy3에서는 실행시, 자주 쓰이는 코드를 캐싱하는 기능이 있기 때문에 ,
#즉  메모리를 조금 더 사용하여 그것들을 저장하고 있어, 실행속도를 개선할 수 있다는 것이기 때문에,
#간단한 코드상에서는 Python3가 메모리, 속도 측에서 우세할 수 있는 것이고,
#복잡한 코드(반복)을 사용하는 경우에서는 PyPy3가 우세하기 때문에
#-> 코드 상황에 맞추어 두 구현체(PyPy3, Python3)를 적절하게 사용하는 것이 효율적이라고 할 수 있다.
