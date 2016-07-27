#!/bin/sh
read n
ans=1
i=1
while [ $i -le $n ]
do
  ans=`expr $ans \* $i`
  i=`expr $i \+ 1`
done

echo $ans
