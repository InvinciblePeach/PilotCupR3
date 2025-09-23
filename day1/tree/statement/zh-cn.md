{{ self.title() }}

{{ s('description') }}

给定初始以 $1$ 为根的一棵树, 点有点权, 你需要支持一下三种操作:

1. 求子树 $u$ 中点权的最大值;
2. 求子树 $u$ 中点权的和;
3. 将树的根替换为 $u$.

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含两个整数 $c, n$, 其中 $n$ 表示树的点数, $c$ 表示当前为第 $c$ 号测试点, 对于样例, $c = 0$.

第二行包含 $n$ 个整数表示点权.

接下来 $n - 1$ 行每行两个整数描述一条边.

接下来一行一个整数 $m$ 表示操作次数.

接下来 $m$ 行每行两个整数, $op ~ u$, 含义如题目描述所示.

{{ s('output format') }}

{{ self.output_file() }}

对于每个 $op \in \{1, 2\}$, 你需要输出一行表示询问的答案.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

{{ s('sample', 2) }}

{{ self.sample_file() }}

{{ s('subtasks') }}

{{ tbl('data') }}

对于 $100%$ 的数据保证 $n, m \le 100000$.