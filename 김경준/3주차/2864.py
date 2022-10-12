a,b=input().split()
min=int(a.replace("6","5"))+int(b.replace("6","5"))
#a의 문자열에서 6을 5로 바꾼다
max=int(a.replace("5","6"))+int(b.replace("5","6"))
print(min,max)
