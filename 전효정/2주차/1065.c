n,count=input(),0

def len3(n):
    global count
    count=99
    for i in range(100, int(n)+1):
        i=str(i)
        if int(i[1])==(int(i[0])+int(i[2]))/2:
            count+=1
        else:
            continue
    return count

if len(n)==1 or len(n)==2:
    for i in range(int(n)):
        count+=1
else:
    len3(n)

print(count)