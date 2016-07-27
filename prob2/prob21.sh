#!/bin/sh
for file in *
do
  size=$(wc -c $file| awk '{print $1}')
  if [ $size -gt $1 ]
  then
    echo $file
  fi
done
