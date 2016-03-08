# Uses python3
n = int(input())
a = [int(x) for x in input().split()]
assert(len(a) == n)

result = 0

#if a[0]>a[1]:
#    max_1 = a[0]
#    max_2 = a[1]
#else:
#    max_1 = a[1]
#    max_2 = a[0]
max_1 = 0
max_2 = 0

for i in range(0, n):
    if a[i] >= max_1:
        max_2 = max_1
        max_1 = a[i]
    elif a[i] > max_2:
        max_2 = a[i]

result = max_1*max_2
        
print(result)
