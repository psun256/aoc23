import sys
import re
import itertools
import collections
from collections import defaultdict
from collections import Counter

io = sys.argv[1] if len(sys.argv) > 1 else "d2s.in"

inp = [x for x in open(io).read().strip().splitlines()]
print(inp)

cnt = 0
a2 = 0
for line in inp:
    mxred, mxgreen, mxblue = 0, 0, 0
    id = line.split()[1][:-1]
    print(id)
    s = line.split(';')
    s[0] = s[0].split(':')[1]
    colors = defaultdict(int)
    possible = True
    for i in range(len(s)):
        s[i] = s[i].replace(',', '').split()
        print(s[i])
        for j in range(len(s[i])//2):
            colors[s[i][j*2+1]] += int(s[i][j*2])
        if colors['red'] > 12 or colors['green'] > 13 or colors['blue'] > 14:
            possible = False
        mxred = max(mxred, colors['red'])
        mxgreen = max(mxgreen, colors['green'])
        mxblue = max(mxblue, colors['blue'])
        colors = defaultdict(int)
    a2 += mxred* mxgreen* mxblue
    print(mxred, mxgreen, mxblue)
    mxred, mxgreen, mxblue = 0, 0, 0
    if possible:
        cnt += int(id)
print(cnt)
print(a2)
