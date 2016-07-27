#!/bin/sh
echo `expr $(du | wc -l) \- 1`
