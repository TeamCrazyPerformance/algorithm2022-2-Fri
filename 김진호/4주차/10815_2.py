import sys

input = sys.stdin.readline

N = int(input())
cards = set(map(int, input().split()))
M = int(input())
num_list = list(map(int, input().split()))
for num in num_list:
    res = 1 if num in cards else 0
    print(res, end=" ")