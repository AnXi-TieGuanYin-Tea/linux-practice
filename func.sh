#!/bin/bash

function factorial {
  if [ $1 -le 1 ]
  then
    echo 1
  else
    local val=$(factorial `expr $1 \- 1`)
    echo `expr $val \* $1`
  fi
}

function factorial2 {
  if [ $1 -le 1 ]
  then
    return 1
  else
    factorial2 `expr $1 \- 1`
    return `expr $? \* $1`
  fi
}


read x
factorial $x
factorial2 $x
echo $?
