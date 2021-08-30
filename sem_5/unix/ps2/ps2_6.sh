#!/bin/bash

filSize () {
	if [ $# = 0 ]; then
		files=$(ls)
	else
		file=$@
	fi
	declare -i sum=0
	for file in $files
	do
		if [ -f $file ]; then
			size=$(stat -c %s $file)
			sum=$(expr $sum + $size)
			# echo "file name: $file, size: $(stat -c %s $file)"
		# else
			# echo "'$file' is not a file"
		fi
	done
	echo $sum
	return $sum
}

echo $(filSize $@)