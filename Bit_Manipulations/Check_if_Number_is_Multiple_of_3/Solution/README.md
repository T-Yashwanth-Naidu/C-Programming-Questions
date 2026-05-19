// @Author: Rohith B Narasimhamurthy (https://github.com/rohith-bn)


Logic behind the code of figuring out if the number is multiple of 3 or not using bit maupulation.

Think of each binary place by its remainder when divided by 3.

Binary place values:

16  8  4  2  1
Remainders % 3:

16 % 3 = 1
8  % 3 = 2
4  % 3 = 1
2  % 3 = 2
1  % 3 = 1
So the pattern is:

1, 2, 1, 2, 1
Now the key idea:

2 mod 3 is same as -1 mod 3
Why?

Because:

2 = 3 - 1
So instead of saying remainder 2, we can think “minus 1”.

That gives:

16  8   4   2   1
+1 -1  +1  -1  +1
So for each 1 bit:

if it is in a +1 position, add 1
if it is in a -1 position, subtract 1
If final result is divisible by 3, then original number is divisible by 3.

Example 1: 9 is divisible by 3

9 = 1001
Place values:

8 4 2 1
1 0 0 1
Sign pattern:

8   4   2   1
-1 +1  -1  +1
Only 8 and 1 bits are set:

8 position  => -1
1 position  => +1
Total:

-1 + 1 = 0
0 is divisible by 3, so 9 is divisible by 3.

Example 2: 10 is not divisible by 3

10 = 1010
Set bits: 8 and 2.

8 position => -1
2 position => -1
Total:

-1 - 1 = -2
-2 is not divisible by 3, so 10 is not divisible by 3.

Example 3: 11 is not divisible by 3

11 = 1011
Set bits: 8, 2, and 1.

8 position => -1
2 position => -1
1 position => +1
Total:

-1 - 1 + 1 = -1
-1 is not divisible by 3, so 11 is not divisible by 3.

Example 4: 21 is divisible by 3

21 = 10101
Place values:

16  8  4  2  1
1   0  1  0  1
Signs:

16   8   4   2   1
+1  -1  +1  -1  +1
Set bits: 16, 4, 1.

+1 +1 +1 = 3
3 is divisible by 3, so 21 is divisible by 3.

The shortcut:

count 1s in even positions - count 1s in odd positions
If that difference is divisible by 3, number is divisible by 3.

Position from right:

position: 4 3 2 1 0
value:   16 8 4 2 1
sign:    + - + - +
So:

even positions => +1
odd positions  => -1

