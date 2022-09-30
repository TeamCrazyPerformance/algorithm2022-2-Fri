count,n=0,int(input())

for i in range(n):
    s,w=input(),0
    #하나의 단어에 대하여 그룹단어인지 파악하기. 그룹단어라면 count+=1
    while True:
        if len(s)==0:
            break
        #s[0]인 문자의 개수 세기 (한글자에 대하여)
        List=[]
        for index,val in enumerate(s):
            if val==s[0]:
                List.append(index)
        s=s.replace(s[0], '')
    #그룹단어가 아님.
        if List[-1]-List[0]+1!=len(List):
            w=1
            break
    
    if w==0:
        count+=1
        
            
print(count)