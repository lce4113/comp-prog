"""
ID: 2ommahe1
LANG: PYTHON3
TASK: test
"""

import sys


def main(f):
    args = f.split('\n')
    total = int(args[0])
    petals = list(int(n) for n in args[1].split(' '))
    for i in range(len(petals)):
        for j in range(i+2, len(petals)+1):
            photo = petals[i:j]
            average = sum(photo) / len(photo)
            for flower in photo:
                if flower == average:
                    total += 1
                    break
    return total


# standard_input = '5\n1 2 3 4 5'
print(main(sys.stdin.read()))
