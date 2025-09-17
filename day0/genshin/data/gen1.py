from cyaron import *
import math

MAXV = 2 ** 30 - 1
g = [[]] * 100010
f = [0] * 100010

def dfs(u, fa, val, dep):
    f[u] = val
    k = len(g[u])
    # print(f'{u} {val}')
    if (dep % round(max(1, math.log2(n) - 5)) == 0): t = [randint(0, k - 1) for _ in range(30)]
    for i in range(k):
        v = g[u][i]
        if v == fa: continue
        tmp = val
        if (dep % round(max(1, math.log2(n) - 5)) == 0):
            tmp = 0
            for _ in range(30):
                if t[_] == i: tmp |= (val >> _ & 1) << _
        dfs(v, u, tmp, dep + 1)

def work(n, q, fin):
    fin.write(f'{n} {q}\n')
    tree = Graph.tree(n)
    for i in range(1, n + 1): g[i] = []
    for e in tree.iterate_edges(): # 遍历所有边，其中edge内保存的也是Edge对象
        g[e.start] += [e.end]
        g[e.end] += [e.start]
    dfs(1, 0, randint(0, MAXV), 1)
    w = [randint(0, MAXV) & f[_] for _ in range(1, n + 1)]
    if n <= 10: print(' '.join(map(str, f[1:n + 1])))
    fin.write(' '.join(map(str, w)))
    fin.write('\n')
    for e in tree.iterate_edges(): # 遍历所有边，其中edge内保存的也是Edge对象
        fin.write(f"{e.start} {e.end}\n")
    for _ in range(q):
        op = randint(1, 10)
        if op == 1:
            u = randint(1, n)
            fin.write(f'1 {u} {f[u] & randint(1, n)}\n')
        else:
            rt = randint(1, n)
            u = rt
            v = rt
            while (True):
                if (randint(0, 100) == 0): break
                if (len(g[u]) == 1): break
                u = g[u][randint(0, len(g[u]) - 1)]
            while (True):
                if (randint(0, 100) == 0): break
                if (len(g[v]) == 1): break
                v = g[v][randint(0, len(g[v]) - 1)]

            fin.write(f'2 {u} {v} {randint(0, MAXV)}\n')

N = [0, 10, 5000, 50000, 100000, 100000, 100000]
for i in range(6, 7):
    for j in range(1, round(4, 6)):
        print(f'working in: {i}-{j}.in')
        n = N[i]
        n = randint(max(2, n - 100), n)
        q = randint(max(5, N[i] - 100), N[i])
        with open(f'{i}-{j}.in', 'w+') as file:
            work(n, q, file)