#!/bin/sh 

set $(date)
echo ${1%?}y ${2%?}m ${3%?}d
