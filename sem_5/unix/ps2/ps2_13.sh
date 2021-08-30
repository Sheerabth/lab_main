#!/bin/bash

path='.'

if [ $# = 1 ]; then
    if [ -d $1 ]; then
        path=$1
    else
        echo "Enter path of a directory"
        exit 1
    fi
fi

declare -i sum=0

for file in $(ls $path)
do
    echo $file
    size=$(stat -c %s $path/$file)
    if [ size -gt 10000 ]; then
        created=$(stat -c %W $path/$file | cut -d" " -f1)
        current=$(date +"%s")
        days=$(expr 10 \* $(expr 24 \* $(expr 60 \* 60)))
        if [ $(expr $created - $current) -gt days ]; then
            sum=$(expr $sum + $size)
        fi
    fi
done
echo "Sum of size files in the given directory, larger than 10kb and older than 10 days is $sum bytes"
