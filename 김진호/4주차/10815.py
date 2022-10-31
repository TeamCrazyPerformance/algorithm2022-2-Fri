import sys

input = sys.stdin.readline

N = int(input())

cards = list(map(int, input().split()))
cards.sort()


def bs(target):
    left, right = 0, len(cards) - 1

    while left <= right:
        mid = (left + right) // 2

        if cards[mid] < target:
            left = mid + 1
        elif cards[mid] == target:
            return 1
        else:
            right = mid - 1
    return 0


M = int(input())
num_list = list(map(int, input().split()))
for num in num_list:
    print(bs(num), end=" ")