{{ self.title() }}

{{ s('description') }}

给定一棵 $n$ 个点的树, 点有点权, 有 $q$ 个操作，操作有两种:

- $1~x~c$ 将 $x$ 子树中所有点的点权异或上 $c$;
- $2~u~v~w$ 询问 $u$ 到 $v$ 的简单路径中所选出任意一个点权的子集与 $w$ 的异或和最大为多少.

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含两个正整数 $n, q$, 保证 $n, q \le {{ args['n'].hn() }}$.

输入的第二行包含 $n$ 个正整数, 第 $i$ 个正整数表示点 $i$ 的点权.

接下来 $n - 1$ 行每行两个整数 $u, v$ 表示一条边, 满足 ($u, v < n, u \neq v$).

接下来 $m$ 行每行三个或四个正整数, 含义如题目描述所示.

{{ s('output format') }}

{{ self.output_file() }}

输出一行一个整数, 表示所有询问的答案之和.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_file() }}

{{ s('subtasks') }}

{{ tbl('data') }}