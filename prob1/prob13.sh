#!/bin/sh
echo $PWD | tr -dc '/' | wc -c
