import sys
import re
import itertools
import collections
from collections import defaultdict
from collections import Counter

io = sys.argv[1] if len(sys.argv) > 1 else "d3.in"

inp = [x for x in open(io).read().strip().splitlines()]
inp.insert(0, '.' * (2 + len(inp[0])))
inp.append('.' * (2 + len(inp[0])))
for i in range(len(inp)):
    inp[i] = '.' + inp[i] + '.'

dx = [-1, 0, 1, -1, 1, -1, 0, 1]
dy = [-1, -1, -1, 0, 0, 1, 1, 1]
sum = 0
sum2 = 0
for i in range(len(inp)):
    j = 0
    while j < len(inp[i]):
        add = False
        if (inp[i][j].isdigit()):
            num = ""
            oldj = j
            while (inp[i][j].isdigit()):
                num += inp[i][j]
                j += 1
            j = oldj
            while (inp[i][j].isdigit()):
                for k in range(8):
                    if (not inp[i+dy[k]][j+dx[k]].isdigit() and inp[i+dy[k]][j+dx[k]] != '.'):
                        add = True
                j += 1
        if (add):
            sum += int(num)
        j += 1

print(sum)
vis = set()

for i in range(len(inp)):
    for j in range(len(inp[i])):
        if (inp[i][j] == '*'):
            cnt = 0
            nums = []
            for k in range(8):
                if (inp[i+dy[k]][j+dx[k]].isdigit() and (i+dy[k], j+dx[k]) not in vis):
                    vis.add((i+dy[k], j+dx[k]))
                    cnt += 1
                    ci, cj = i+dy[k], j+dx[k]
                    num = ""
                    while (inp[ci][cj].isdigit()):
                        cj -= 1
                    cj += 1
                    while (inp[ci][cj].isdigit()):
                        num += inp[ci][cj]
                        cj += 1
                        vis.add((ci, cj))
                    nums.append(int(num))
            if (cnt == 2):
                sum2 += nums[0] * nums[1]

print(sum2)
