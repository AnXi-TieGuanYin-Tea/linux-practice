#!/bin/sh 

printf "Enter one number : "
read x
echo $x | grep -o .
