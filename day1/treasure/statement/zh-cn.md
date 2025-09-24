{{ self.title() }}

{{ s('background') }}

{{ img('p1.png', size = 0.7, align = 'middle') }}

{{ img('p2.png', size = 0.7, align = 'middle') }}

我们在弱化版中删掉了方差!!!

{{ s('description') }}

现在有 $N$ 个垃圾和 $M$ 个宝藏, 每个东西都有一个正权 $p_i$, 随机抽取 $K$ 次, 一个抽取方案 $S$ 的概率为 $\sum_{a\in S}p_a$, 保证 $\sum_{S \subseteq U \wedge |S| = K}\sum_{a\in S }p_a=1$

记抽取得到的宝藏个数为 $A$, 求 $A$ 的期望, 答案对 $998244353$ 取模.

{{ s('input format') }}

{{ self.input_file() }}

输入第一行两个整数 $N, M, K$.

接下来一行 $N$ 个整数表示垃圾的 $p_i$.

接下来一行 $M$ 个整数表示宝藏的 $p_i$.

保证输入的所有数字在 $[0, 998244353)$ 范围内.

{{ s('output format') }}

{{ self.output_file() }}

输出一行一个整数, 分别表示 $A$ 的期望.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

四个数字分别是: $\frac{1}{30},\frac{2}{15},\frac{1}{10},\frac{1}{15}$ 在模 $998244353$ 意义下的值. 不难发现:

- 有$\frac{1}{6}$ 的概率 $A = 0$;
- 有$\frac{2}{3}$ 的概率 $A = 1$;
- 有$\frac{1}{6}$ 的概率 $A = 2$.

得到: $E(A) = 1$

{{ s('sample', 2) }}

{{ self.sample_file() }}

该组样例满足子任务 2 的性质.

{{ s('sample', 3) }}

{{ self.sample_file() }}

该组样例满足子任务 3 的性质.

{{ s('subtasks') }}

{{ tbl('data') }}