#!/bin/sh
if [ -z $1 ]
then
  dir=.
else
  dir=$1
fi

echo $dir

for file in $(ls $dir)
do
  if [ -s $dir/$file ]
  then
    echo $dir/$file
  else
    rm $dir/$file
  fi
done
