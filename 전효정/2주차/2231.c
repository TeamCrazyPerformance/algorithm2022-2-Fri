N=int(input())

def Sep(i):
    Sum=i
    s=str(i)
    for j in s:
        Sum+=int(j)
    if Sum==N:
        return i
    return 0

t=N-len(str(N))*9 if N>18 else 1

if N==1:
    result=0
    
for i in range(t, N):
    result=Sep(i)
    if result!=0:
        break

    
print(result)