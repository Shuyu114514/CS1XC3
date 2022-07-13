#!/bin/bash
path="$1"
if [ $1 ]; then
    gcc -L$path -Wl,rpath=$path -Wall -o top top.c lLab6Part5
fi