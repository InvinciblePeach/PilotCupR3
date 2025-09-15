{{ self.title() }}

{{ s('description') }}

小 A 喜欢拆分数字.

他现在有一个数 $n$ , 请你构造一组 $p,q,s,t$ , 使得 $pq-st=n$, 并且 $|p-q|+|s-t|$ 最小, 其中 $p,q,s,t$ 为不超过 $n$ 的自然数.

{{ s('input format') }}

{{ self.input_file() }}

第 $1$ 行 $1$ 个整数 $T$ , 表示询问组数, 保证 $1 \leq T \leq {{ args['T'].hn() }}$.

接下来 $T$ 行, 每行 $1$ 组数据, 包含 $1$ 个正整数 $n$.

{{ s('output format') }}

{{ self.output_file() }}

输出 $T$ 行, 每行 $4$ 个整数, 分别为 $p,q,s,t$.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

对于第一组询问, 构造 $3 = 2 * 2 - 1 * 1$, 代价为 $|2 - 2| + |1 - 1| = 0$ 最小.

对于第二组询问, 构造 $9 = 5 * 5 - 4 * 4$, 代价为 $|5 - 5| + |4 - 4| = 0$ 最小.

{{ s('subtasks') }}

{{ tbl('data') }}