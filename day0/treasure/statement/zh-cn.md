{{ self.title() }}

{{ s('background') }}

{{ img('p1.png', size = 0.7, align = 'middle') }}

{{ img('p2.png', size = 0.7, align = 'middle') }}

{{ s('description') }}

现在有 $N$ 个垃圾和 $M$ 个宝藏, 每个东西都有一个正权 $p_i$, 随机抽取 $K$ 次, 一个抽取方案 $S$ 的概率为 $\sum_{a\in S}p_a$, 保证 $\sum_{S \subseteq U \wedge |S| = k}\sum_{a\in S }p_a=1$

记抽取得到的宝藏个数为 $A$, 求 $A$ 的期望和方差, 答案对 $998244353$ 取模.

**题目开启 Special Judge**, 如果输出文件的第一行正确, 你将获得该测试点 $30\%$ 的分数, 每个子任务的得分百分比为该子任务下得分百分比**最低**的测试点的百分比.

{{ s('input format') }}

{{ self.input_file() }}

输入第一行两个整数 $N, M, K$.

接下来一行 $N$ 个整数表示垃圾的 $p_i$.

接下来一行 $M$ 个整数表示宝藏的 $p_i$.

保证输入的所有数字在 $[0, 998244353)$ 范围内.

{{ s('output format') }}

{{ self.output_file() }}

输出两行两个整数, 分别表示 $A$ 的期望和方差.

**为了保证 Checker 正常工作, 即便你只完成了第一问也请在第二行随意输出一个整数, 否则可能发生意想不到的错误.**

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

四个数字分别是: $\frac{1}{30},\frac{2}{15},\frac{1}{10},\frac{1}{15}$ 在模 $998244353$ 意义下的值. 不难发现:

- 有$\frac{1}{6}$ 的概率 $A = 0$;
- 有$\frac{2}{3}$ 的概率 $A = 1$;
- 有$\frac{1}{6}$ 的概率 $A = 2$.

得到: $E(A) = 1, D(A) = \frac{1}{3}$

{{ s('sample', 2) }}

{{ self.sample_file() }}

该组样例满足子任务 2 的性质.

{{ s('sample', 3) }}

{{ self.sample_file() }}

该组样例满足子任务 3 的性质.

{{ s('subtasks') }}

{{ tbl('data') }}