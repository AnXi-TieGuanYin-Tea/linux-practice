#!/bin/sh

checkValidity() {
  val=$(echo $1 | grep '^[-0-9a-zA-Z]*$')
  if [ $val ]
  then
    return 0
  else
    return 1
  fi
}

echo -n 'Enter input : '
read input
if ! checkValidity $input
then
  echo NOT OK
  exit 1
else
  echo OK
fi

