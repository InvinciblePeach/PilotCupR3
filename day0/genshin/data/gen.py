from cyaron import *

MAXV = 2 ** 31 - 1

def work(n, q, fin):
    w = [randint(0, MAXV) for _ in range(n)]
    print(f'{n} {q}')
    print(' '.join(map(str, w)))
    tree = Graph.tree(n)
    for e in tree.iterate_edges(): # 遍历所有边，其中edge内保存的也是Edge对象
        print(f"{e.start} {e.end}") # 输出这条边，以u v w的形式

    for _ in range(q):
        op = randint(1, 2)
        if op == 1:
            print(f'{op} {randint(1, n)} {randint(1, n)}')
        elif op == 2:
            print(f'{op} {randint(1, n)} {randint(1, n)} {randint(0, MAXV)}')

for i in range(1, 7):
    for j in range(1, round(i*5.2)):
        print(f'working in: {i}-{j}.in')
        with open(f'{i}-{j}.in', 'w+') as file:
            pass