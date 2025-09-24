{{ self.title() }}

{{ s('description') }}

给定一棵有 $n$ 个节点的有根树, 初始以 $1$ 为根, 每个点有一个权值 $a_i$. 你需要支持以下三种操作:

- $1~u~x$ 将 $a_u$ 修改为 $x$;
- $2~u$ 求子树 $u$ 中的最大权值;
- $3~u$ 将树的根替换为 $u$.

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含一个整数 $c$, 表示当前测试点编号. 对于样例, $c=0$.

第二行包含一个整数 $n$, 表示树的节点数量.

第三行包含 $n$ 个正整数, 第 $i$ 个正整数表示第 $i$ 个节点的权值.

接下来 $n-1$ 行, 每行两个正整数 $u,v$, 表示这两个节点之间有一条边.

接下来 $m$ 行, 每行若干个正整数, 表示一次操作, 含义如题目描述所示.

{{ s('output format') }}

{{ self.output_file() }}

对于每个操作 2, 你需要输出一行表示询问的答案.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('sample', 3) }}

{{ self.sample_file() }}

{{ s('subtasks') }}

{{ tbl('data') }}

对于 $100\%$ 的数据保证 $n, m \le {{ args['n'].hn() }}$, 输入的所有数据 $\le 10^9$.