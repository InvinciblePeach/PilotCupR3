from cyaron import *
import os

# Returns the modular inverse of a prime modulo p.
# Use built-in pow function.

mod = int(998244353)
def inverse(a):
    return pow(a, mod - 2, mod)

frac = [1]

for i in range(1, 200000): frac += [i * frac[i - 1] % mod]

def C(n, m): return frac[n] * inverse(frac[m]) % mod * inverse(frac[n - m]) % mod

N = [0, 10, 100, 1000, 100000]

for i in range(1, 5):
    for j in range(1, 6):
        print(f'working in: {i}-{j}.in')
        with open(f'{i}-{j}.in', 'w+') as file:
            n = randint(max(1, N[i] - 100), N[i])
            m = randint(max(1, N[i] - 100), N[i])
            k = randint(1, n + m)

            a, b = [], []
            sum = 0

            for k in range(n - 1):
                a += [randint(0, mod - 1)]
                sum = (sum + a[k]) % mod
            for k in range(m):
                b += [randint(0, mod - 1)]
                sum = (sum + b[k]) % mod

            a += [(inverse(C(n + m - 1, k - 1)) - sum + mod) % mod]

            file.write(f'{n} {m} {k}')
            file.write('\n')
            file.write(' '.join(map(str, a)))
            file.write('\n')
            file.write(' '.join(map(str, b)))
            file.write('\n')
        os.system(f'./a.out < {i}-{j}.in > {i}-{j}.ans')