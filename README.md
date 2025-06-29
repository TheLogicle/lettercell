# LetterCell

⚠️ **Error checks have not been implemented yet, so errors in LetterCell code could cause a SIGABRT in the interpreter**

## Description

LetterCell is an esoteric programming language. It is based upon the concept of a readhead which can freely traverse over an infinitely long line of memory cell slots.


Here is a visualization:
```
                   
                  readhead --->    |015| 
                                    \ /
                                     v

... |     | 000 | 053 |     | 125 |     | 002 | ...  <--- memory slots
```

- The readhead can freely move left and right.
- The readhead has a space in it where it can store a memory cell.
	+ Memory cells hold exactly one byte of data.
- The readhead can spawn a new cell in its storage area, and it can also vaporize the cell it is holding.
- It can drop cells into the line of slots, and it can also pick up cells from there.
- It can only change the value of the cell it is currently holding.

## Operations

| Operation | Description |
| :-------: | ----------- |
|    `l`    | Move readhead left one space |
|    `r`    | Move readhead right one space |
|    `zl`   | Move readhead left 16 spaces |
|    `zr`   | Move readhead right 16 spaces |
|    `s`    | Spawn new memory cell with value 0 |
|    `v`    | Vaporize current memory cell |
|    `p`    | Pick up memory cell |
|    `d`    | Drop memory cell |
|    `t`    | Increment current memory cell |
|    `b`    | Decrement current memory cell |
|    `zt`   | Increment current memory cell by 16 |
|    `zb`   | Decrement current memory cell by 16 |
|`k`, `kk`, `kkk`, ...| Create a label with the same amount of characters as `k`'s (Example: `kx` is a label named `x`, and `kkkfoo` is a label named `foo`)
|`g`, `gg`, `ggg`, ...| Go to label (same syntax as `k` declaration). This will only go to the label if **ONE** of the following conditions are met:<br>1. The readhead is NOT currently holding a cell<br>2. The readhead IS currently holding a cell, and it is NOT set to `0`|