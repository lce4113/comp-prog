"""
ID: 2ommahe1
LANG: PYTHON3
TASK: test
"""

import sys


class Cow:

    def __init__(self, data):
        self.dir = data[0]
        self.x = int(data[1])
        self.y = int(data[2])

    def dist(self, x, y):
        if self.dir == 'N':
            return y - self.y
        return x - self.x


f = sys.stdin.read()
args = f.split('\n')[1:-1]
cows = []
for arg in args:
    cow = Cow(arg.split(' '))
    cows.append(cow)


def compare():
    for i in range(len(cows)):
        for j in range(i+1, len(cows)):

            cow1 = cows[i]
            cow2 = cows[j]
            if cow1.dir == cow2.dir:
                continue

            if cow1.dir == 'N':
                meetX = cow1.x
                meetY = cow2.y
            else:
                meetX = cow2.x
                meetY = cow1.y

            dist1 = cow1.dist(meetX, meetY)
            dist2 = cow2.dist(meetX, meetY)
            if dist1 < 0 or dist2 < 0:
                continue

            if dist1 > dist2:
                print(i, j, hasattr(cow2, 'end') and cow2.end < dist2)
                if hasattr(cow2, 'end') and cow2.end < dist2:
                    if hasattr(cow1, 'end'):
                        del cow2.end
                        compare()
                    continue
                if hasattr(cow1, 'end') and cow1.end < dist1:
                    continue
                cow1.end = dist1
            elif dist1 < dist2:
                if hasattr(cow1, 'end') and cow1.end < dist1:
                    if hasattr(cow2, 'end'):
                        print("himself")
                        del cow1.end
                        compare()
                    continue
                if hasattr(cow2, 'end') and cow2.end < dist2:
                    continue
                cow2.end = dist2


compare()
compare()


out = []
for cow in cows:
    end = cow.end if hasattr(cow, 'end') else "Infinity"
    out.append(end)


print(' '.join(str(n) for n in out))
