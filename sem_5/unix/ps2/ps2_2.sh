#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Invalid number of arguments"
	exit 1
fi

file_name=$1
cont="y"

while [ $cont = "y" ]
do
	echo "1. Write record to file"
	echo "2. Remove a record"
	echo "3. Print list of all books"
	echo "4. Print all books given an author"

	read -p "Enter your choice: " choice

	case $choice in
		'1' )	read -p "Enter the accession-no: " acc_no
				read -p "Enter the name of the book: " book_name
				read -p "Enter the author name: " author
				echo "$acc_no | $book_name | $author" >> $file_name
		;;
		'2' )	if [ ! -e $file_name ]; then
					echo "Invalid file name"
				else
					read -p "Enter the accession-no: " acc_no
					sed -i "/^$acc_no/d" $file_name
				fi
		;;
		'3' )	if [ ! -e $file_name ]; then
					echo "Invalid file name"
				else
					result=$(cut -d \| -f2 < $file_name)
					if [ -z "$result" ]; then
						echo "No books"
					else
						echo "$result"
					fi
				fi
		;;
		'4' )	if [ ! -e $file_name ]; then
					echo "Invalid file name"
				else
					read -p "Enter the author name: " author
					result=$(grep "$author$" $file_name | cut -d \| -f2)
					if [ -z "$result" ]; then
						echo "No books with the given author"
					else
						echo "$result"
					fi
				fi
		;;
		* ) echo "Invalid Command"
	esac

	read -p "Do u want to continue (y/n)? " cont
done