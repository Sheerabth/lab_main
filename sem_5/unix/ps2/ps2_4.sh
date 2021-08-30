#!/bin/bash

read -p "Enter file name: " file_name

if [ ! -e $file_name ]; then
	echo "File does not exists"
else
	echo $(stat $file_name)
	file_type=$(file -b $file_name | grep -o 'text')
	if [ $file_type = "text" ]; then
		echo "Its a text file"
		echo "i. Number of sentences: $(grep -o '[.!?]' < $file_name | wc -w)"
		echo "ii. Number of words: $(wc -w  < $file_name)"
		echo "iii. Number of words more than 5 characters: $(grep -o '\<[^ ]\{5,\}\>' $file_name | wc -w)"
		echo "iv. Number of words that start with a vowel: $(grep -o '\<[aeiou][^ ]*\>' $file_name | wc -w)"
		echo "v. Number of articles in the text file: $(grep -o '\<a\>\|\<an\>\|\<the\>' $file_name | wc -w)"
		echo "vi. Access permissions: $(stat --printf=%A'\n' $file_name)"
	else
		echo "Its not a text file"
	fi
fi