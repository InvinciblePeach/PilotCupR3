{{ self.title() }}

{{ s('description') }}

小 A 喜欢研究区间的性质.

他现在有一个长为 $n$ 的数列 $a_i$ .

你需要回答 $m$ 组询问, 每次给定一组整数 $x_i,y_i>0$, 并回答有多少整数对 $l,r\in[1,n]$ 满足如下条件:

* $r-l > 2$
* $(a_l \operatorname
{xor} a_r) + (a_l\operatorname
{or}a_r)+(a_l\operatorname
{and}a_r)+\bigoplus_{i=l}^ra_i=x(\sum_{i=l}^{r-1}a_i\operatorname
{and}a_{i+1})+y(\sum_{i=l}^{r-1}a_i\operatorname
{or}a_{i+1})$

其中, $\bigoplus,\text{xor}$ 表示按位异或; $\text{or}$ 表示按位或; $\text{and}$ 表示按位与.

**注意: 对任意整数 $i,j\in[1,m]$, 保证 $(x_i-x_j)(y_i-y_j)\geq0$ .**

{{ s('input format') }}

{{ self.input_file() }}

第 $1$ 行输入 $2$ 个整数 $n,m$ , 分别表示数列长度和测试组数.

第 $2$ 行输入 $n$ 个正整数, 表示  $a_i$.

接下来 $m$ 行, 每行输入一组 $x_i,y_i$, 表示一组询问.

{{ s('output format') }}

{{ self.output_file() }}

输出 $m$ 行, 每行 $1$ 个整数, 表示该组询问的答案.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_file() }}

{{ s('sample', 3) }}

{{ self.sample_file() }}

{{ s('sample', 4) }}

{{ self.sample_file() }}

{{ s('sample', 5) }}

{{ self.sample_file() }}

{{ s('sample', 6) }}

{{ self.sample_file() }}

{{ s('subtasks') }}

{{ tbl('data') }}