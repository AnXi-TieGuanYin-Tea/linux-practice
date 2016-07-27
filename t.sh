a=90
b=100

test $a -gt $b
echo $?

if [ $a -lt $b ]
then
  echo ok
fi

if [ 0 ]
then
  echo 0 is true
fi

if [ 1 ]
then
  echo 1 is true
fi
