#2805

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
