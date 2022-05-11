# push_swap

## 説明
このPush_swapは、2つのスタック上に格納されたデータを限られた命令で、なるべく最小の命令回数で昇順にソートする課題です。

## 課題条件
gcc または Clang
GNU Make

## 命令
sa: (swap a)スタックaの先頭の2つの要素を入れ替える。
sb: (swap b)スタックbの先頭の2つの要素を入れ替える。

pa: (push a) bの先頭の要素を取り、aの先頭に置く。
pb: (push b) aの先頭の要素を取り出し、bの先頭に置く。

ra: (rotate a) スタックaのすべての要素を1つずつ上に移動する。
rb: (rotate b) スタックbのすべての要素を1つずつ上に移動する。

rra: (reverse rotate a) スタックaのすべての要素を1つ下に移動する。
rrb: (reverse rotate b) スタックbのすべての要素を1つ下に移動する。

## 実行方法
```
git clone https://github.com/hohnuki/push_swap
cd push_swap
make
```
```
./push_swap 22 55 66 44 88 11
```
