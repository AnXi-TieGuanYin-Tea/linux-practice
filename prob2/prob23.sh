#!/bin/sh
name=$1
if [ -d $name ]
then
  echo $name is a directory
else
  echo $name is a file
  if [ -r $name ]
  then
    echo $name is readable
  fi
  if [ -w $name ]
  then
    echo $name is writable
  fi
  if [ -x $name ]
  then
    echo $name is executable
  fi
fi

