import sys
import re
import itertools
import collections
from collections import defaultdict
from collections import Counter

io = sys.argv[1] if len(sys.argv) > 1 else "d5.in"

inp = [x for x in open(io).read().strip().split('\n\n')]

seeds, *maps = inp
seeds = list(map(int, seeds.split(':')[1].split()))
maps = [[list(map(int, line.split())) for line in mp.splitlines()[1:]] for mp in maps]

def clamp(a, b, c, d):
    return max(a, c), min(b, d)

for mp in maps:
    mp.sort(key=lambda x: x[1])
    n = len(mp)
    mp.append([0, 0, mp[0][1]])
    for i in range(n-1):
        s = mp[i][1] + mp[i][2]
        e = mp[i+1][1]
        mp.append([s, s, e-s])
    mp.append([mp[-1][1] + mp[-1][2], mp[-1][1] + mp[-1][2], 10**16])

p1, p2 = 1e15, 1e15
for seed in seeds:
    s = seed
    for mp in maps:
        for rng in mp:
            a, b, c = rng
            c += b-1
            if b <= s <= c:
                s += a-b
                break
    p1 = min(p1, s)

seeds = zip(seeds[::2], seeds[1::2])
seeds = [(s, s+e) for s, e in seeds]

for seed in seeds:
    cur = [seed]
    for mp in maps:
        nxt = []
        while cur:
            s, e = cur.pop()
            for rng in mp:
                a, b, c = rng
                ns, ne = clamp(s, e, b, b+c)
                if ne-ns > 0: # non-empty range
                    nxt.append((ns+a-b, ne+a-b))
                    cur.append((s, b)) # left
                    cur.append((b+c, e)) # right
                    break
        cur = nxt
    p2 = min(p2, min(cur)[0])
print(p1, p2)
