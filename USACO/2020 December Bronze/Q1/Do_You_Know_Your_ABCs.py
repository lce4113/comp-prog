"""
ID: 2ommahe1
LANG: PYTHON3
TASK: test
"""


def main(f):
    nums = list(map(int, f.split(' ')))
    largest = max(nums)

    def order(a, b, c):
        if a < b:
            if b < c:
                abc = [a, b, c]
            elif a < c:
                abc = [a, c, b]
            else:
                abc = [c, a, b]
        else:
            if c < b:
                abc = [c, b, a]
            elif c < a:
                abc = [b, c, a]
            else:
                abc = [b, a, c]
        return abc

    for i in range(len(nums)):
        for j in range(i, len(nums)):
            for k in range(j, len(nums)):
                a, b, c = nums[i], nums[j], nums[k]
                if a + b + c == largest:
                    abc = order(a, b, c)
                    return ' '.join(str(n) for n in abc)


# standard_input = "2 7 11 4 9 2 9"
print(main(input()))
