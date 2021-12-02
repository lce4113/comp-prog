b = []
while True:
    a = input()
    if not a:
        break
    b.append(int(a))

c = 0
for i in range(len(b) - 3):
    if b[i] < b[i + 3]:
        c += 1

print(c)
