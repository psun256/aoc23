import sys
import re
import itertools
import collections
from collections import defaultdict
from collections import Counter

io = sys.argv[1] if len(sys.argv) > 1 else "d1.in"

inp = [x for x in open(io).read().strip().splitlines()]
#print(inp)

nums_conv = {
    "one": 1, "two": 2, "three": 3, "four": 4, "five" : 5, "six": 6, "seven": 7, "eight": 8, "nine": 9, "zero": 0,
    "1": 1, "2": 2, "3": 3, "4": 4, "5" : 5, "6": 6, "7": 7, "8": 8, "9": 9, "0": 0
}

sum = 0
for line in inp:
    s = list(filter(lambda x: x.isdigit(), line))
    sum += int(s[0] + s[-1])
print(sum)

sum = 0
for line in inp:
    s = []
    for i in range(len(line)):
        for n in nums_conv:
            if line[i:].startswith(n):
                s.append(nums_conv[n])
    sum += 10*s[0] + s[-1]

print(sum)
