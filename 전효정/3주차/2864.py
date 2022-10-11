import copy

int1, int2 = input().split()
cal1, cal2 = copy.deepcopy(int1), copy.deepcopy(int2)

int1 = int1.replace('6', '5')
int2 = int2.replace('6', '5')

print(int(int1) + int(int2), end=' ')

cal1 = cal1.replace('5', '6')
cal2 = cal2.replace('5', '6')

print(int(cal1) + int(cal2), end=' ')
        
