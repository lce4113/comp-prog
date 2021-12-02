from sys import stdin

x = 0
for line in stdin:
    x = line[:-1]

def asdf(a):
    b = ""
    pchar = a[0]
    n = 0
    for char in a:
        if char == pchar:
            n += 1
        else:
            b += str(n)
            b += str(pchar)
            n = 1
        pchar = char
    b += str(n)
    b += str(pchar)
    return b

for i in range(50):
    x = asdf(x)

print(len(x))
