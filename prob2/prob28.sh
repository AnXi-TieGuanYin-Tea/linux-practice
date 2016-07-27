#!/bin/sh
i=1
for file in *
do
  mv $file $1$(printf "%03d\n" $i).$2
  i=`expr $i \+ 1`
done
