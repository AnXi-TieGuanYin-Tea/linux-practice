#!/bin/sh
for file in $1/*
do
  if [ -x $file ]
  then
    if [ -z $ex ]
    then
      ex=$file
    fi
    if [ $ex -nt $file ]
    then
      ex=$file
    fi
  else
    if [ -z $co ]
    then
      co=$file
    fi
    if [ $co -ot $file ]
    then
      co=$file
    fi
  fi
done

if [ $ex -ot $co ]
then
  echo 소스 코드가 수정되었으니 다시 컴파일하십시오
fi

