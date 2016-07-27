#!/bin/sh 

read x
x2=`expr $x \* $x`
x3=`expr $x2 \* $x \* 2`

echo `expr 2 \* $x3 + 9 \* $x2 \+ 5 \* $x \+ 10`
