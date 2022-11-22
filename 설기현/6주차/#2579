import sys 
lst = []
dp =[]

T = int(sys.stdin.readline())
for i in range(T):
    lst.append(int(sys.stdin.readline()))    

if T ==1: 
    print(lst[0])
elif T == 2: 
    print(sum(lst))
else: 
    dp.append(lst[0]) #1계단만 오른 경우 
    dp.append(max(lst[0]+lst[1],lst[1])) #2계단을 오른 경우 
    dp.append(max(lst[0]+lst[2],lst[1]+lst[2])) #3계단을 오른 경우 
    for i in range(3,T): #i+1번째 계단을 오른 경우 
        dp.append(max(dp[i-2]+lst[i], dp[i-3]+lst[i-1]+lst[i]))  #1칸 올라가는 건 먼저 나오면 안된다. 
    print(dp[-1])
