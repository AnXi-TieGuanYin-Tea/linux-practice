#!/bin/sh
for i in $(seq 2 $1)
do
  b=0
  for j in $(seq 2 `expr $i \- 1`)
  do
    if [ `expr $i \% $j` -eq 0 ]
    then
      b=1
    fi
  done
  if [ $b -eq 0 ]
  then
    echo $i
  fi
done
