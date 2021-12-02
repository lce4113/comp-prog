from sys import stdin

a = []
for line in stdin:
  a.append(line.split(' '))

x = 0
y = 0
aim = 0
for b in a:
  d = b[0]
  n = int(b[1])
  if d == "forward":
    x += n
    y += aim * n
  if d == "up":
    aim -= n
  if d == "down":
    aim += n

print(x, y)
print(x*y)
