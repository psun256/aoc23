import sys
import re
import math
import itertools
import collections
from collections import defaultdict
from collections import Counter

io = sys.argv[1] if len(sys.argv) > 1 else "d6.in"

inp = [x for x in open(io).read().strip().splitlines()]

t = [int(x) for x in inp[0].split()[1:]]
d = [int(x) for x in inp[1].split()[1:]]

p1 = 1
for i in range(len(t)):
    # (t-x)x - d-1 >= 0
    l = math.ceil((t[i] - math.sqrt(t[i]*t[i] - 4 * (d[i]+1))) / 2)
    r = math.floor((t[i] + math.sqrt(t[i]*t[i] - 4 * (d[i]+1))) / 2)
    p1 *= (r-l+1)

t1 = int(''.join([str(x) for x in t]))
d1 = int(''.join([str(x) for x in d]))

l = math.ceil((t1 - math.sqrt(t1*t1 - 4 * (d1+1))) / 2)
r = math.floor((t1 + math.sqrt(t1*t1 - 4 * (d1+1))) / 2)

print(p1)
print(r-l+1)
