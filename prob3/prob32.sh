#!/bin/sh
num=`expr $PPID \% 100`
try=0
while read -p "Guess? " x
do
  try=`expr $try \+ 1`
  if [ $num -eq $x ]
  then
    echo "Right!! Guessed "$num" in "$try" guesses."
    break
  else
    if [ $num -gt $x ]
    then
      echo "... smaller!"
    else
      echo "... bigger!"
    fi
  fi
done
