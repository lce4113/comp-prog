import math

a = input()
b = int(a)
d = 0
while True:
    a = input()
    if not a:
        break
    c = b
    b = int(a)
    if b > c:
        d+=1
        pass
print(d)
