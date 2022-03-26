# ——— Advent of Code: 2015 Day 11 ———

from sys import stdin

lines = []
for line in stdin:
  lines.append(line)

a = lines[0][:-1]

def test(x):

  for c in x:
    if c == 'i' or c == 'o' or c == 'l':
      return False

  b = False
  for i in range(len(x) - 2):
    if chr(ord(x[i]) + 1) == x[i + 1] and chr(ord(x[i + 1]) + 1) == x[i + 2]:
      b = True
  if not b: return False

  d = 0
  i = 0
  while i < len(x) - 1:
    if x[i] == x[i + 1]:
      d += 1
      i += 1
    i += 1
  if d < 2: return False

  return True

def toN(x):
  X = []
  for c in x:
    X.append(ord(c) - 96)
  return X

def toC(x):
  X = []
  for c in x:
    X.append(chr(c + 96))
  return X

def big(x):
  for a in x:
    if a == 27:
      return True
  return False

def inc(x):
  n = toN(x)
  n[-1] += 1
  while big(n):
    for i in range(len(n)):
      if n[i] > 26:
        n[i] = 1
        n[i - 1] += 1
  return ''.join(toC(n))

a = inc(a)
#while not test(a): a = inc(a)
print(a)
print(chr(96))
