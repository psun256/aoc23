import sys
import re
import itertools
import collections
from collections import defaultdict
from collections import Counter

io = sys.argv[1] if len(sys.argv) > 1 else "d4.in"

inp = [x for x in open(io).read().strip().splitlines()]

s = 0
s2 = 0
combo = [1] * len(inp)

for i in range(len(inp)):
    w, r = inp[i].split('|')
    w, r = w.split()[2:], r.split()
    r = [x for x in r if x in w]
    s += 2**(len(r)-1) if len(r) > 0 else 0
    for j in range(i+1, min(i+len(r)+1, len(inp))):
        combo[j] += combo[i]
    s2 += combo[i]

print(s)
print(s2)