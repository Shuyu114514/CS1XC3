#!/bin/bash

# Use First Argument As Working Directory
WDIR="$1"
cd "$WDIR"

if [ "$#" -gt 2 ] ; then
    varname="$3"
else 
    varname="file1.txt"
fi

if [ "$2" -eq 1 ] ; then
    if [ ! -f $varname ] ; then
        echo $USER > $varname
    fi
elif [ "$2" -eq 2 ] ; then
    if [ -f $varname ] ; then
        if [ ! -d backup ]  ; then 
            mkdir backup
        fi
        cp $varname backup/$varname
    fi
elif [ "$2" -eq 3 ] ; then
    if [ -f backup/$varname ] ; then
        cp backup/$varname $varname
        rm backup/$varname
    fi
fi

if [ "$#" -gt 3 ] ; then
    if [ ! -f excess.txt ] ; then
        touch excess.txt
    else 
        rm excess.txt
        touch excess.txt
    fi
    i=1
    for item in $@ ; do
        if [ "$i" -gt 3 ] ; then
            echo $item >> excess.txt
        fi
        (( i++ ))
    done
fi

echo "Finished"
