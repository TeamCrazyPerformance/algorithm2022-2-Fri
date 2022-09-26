s = list(input())

res = [0] * 26
for c in s:
    res[ord(c) - ord('a')] += 1
print(" ".join(map(str, res)))
