#!/bin/sh
max=0
sum=0
while read f
do
  case $f in
    end)
      echo maximum: $max
      echo sum: $sum
      break;;
    *)
      if [ $f -gt $max ]
      then
        max=$f
      fi
      sum=`expr $sum \+ $f`
      ;;
  esac
done

