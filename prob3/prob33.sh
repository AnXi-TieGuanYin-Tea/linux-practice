#!/bin/bash
voca=("sogang" "linux" "library" "python" "database" "computer" "science" "notebook" "classroom" "programming")
rand=`expr $RANDOM \% 10`
word=${voca[$rand]}
try="abcdefghijklmnopqrstuvwxyz"
guess=0
bad=0

while [ 1 ]
do
  str=$(echo "echo "$word" | sed s'/["$try"]/./g'")
  str=$(eval $str)
  if [ $str = $word ]
  then
    printf "Good job! You guessed %s in %d guesses with %d bad guesses" $word $guess $bad
    break
  fi
  printf "Word is: %s Try what letter next? " $str
  read char
  try=$(echo $try | tr -d $char)
  case $word in
    *"$char"*) printf 'Good guess! [ %s ] is in the word!\n' $char;;
    *) printf 'Sorry, the letter "%s" is not in the word.\n' $char
      bad=`expr $bad \+ 1`;;
  esac
  guess=`expr $guess \+ 1`
done
