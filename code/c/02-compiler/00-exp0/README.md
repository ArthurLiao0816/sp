# 編譯只有 +- 的數字運算式

## exp0 -- 編譯成中間碼


```
$ gcc exp0.c -o exp0
$ ./exp0 '3+(5-8)'
=== EBNF Grammar =====
E=F ([+-] F)*
F=Number | '(' E ')'
==== parse:3+(5-8) ========
t0=3
t1=5
t2=8
t3=t1-t2
t4=t0+t3
```
以static形式宣告的變數只會在程式剛執行時初始化，若此宣告是在函式中進行，則當此函式被呼叫時，static... 將不會再run一次


## exp0hack -- 編譯後產生 hack CPU 的組合語言 (nand2tetris)

```
$ gcc exp0hack.c -o exp0hack
$ ./exp0hack '3+(5-8)'
=== EBNF Grammar =====
E=F ([+-] F)*
F=Number | '(' E ')'
==== parse:3+(5-8) ========
# t0=3
@3
D=A
@t0
M=D
# t1=5
@5
D=A
@t1
M=D
# t2=8
@8
D=A
@t2
M=D
# t3=t1-t2
@t1
D=M
@t2
D=D-M
@t3
M=D
# t4=t0+t3
@t0
D=M
@t3
D=D+M
@t4
M=D
```