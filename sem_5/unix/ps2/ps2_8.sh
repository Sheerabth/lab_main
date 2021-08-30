#!/bin/bash

while [ true ]
do
	echo "a. Content of /etc/passwd (first 15 lines)"
	echo "b. List of users who logged in currently"
	echo "c. Find the sum, product of the digits and factorial of a given number"
	echo "d. Find the value of one number raised to the power of the other. Two numbers should be supplied as arguments"
	echo "e. Exit"
	read -p "Enter your choice: " choice

	case $choice in
		'a' )	`head -n15 /etc/passwd`
		;;
		'b' )	echo "Logged in users: $(users)"
		;;
		'c' )	read -p "Enter the number: " number
				declare -i sum=0
				declare -i product=1
				declare -i factorial=1
				num=$number
				while [ $num -gt 0 ]
				do
					sum=$(expr $sum + $(expr $num % 10))
					product=$(expr $product \* $(expr $num % 10))
					num=$(expr $num / 10)
				done
				echo "Sum of digits: $sum"
				echo "Produc of digits: $product"
				num=$number
				while [ $num -gt 0 ]
				do
					factorial=$(expr $factorial \* $num)
					num=$(expr $num - 1)
				done
				echo "Factorial: $factorial"
		;;
		'd' )	read -p "Enter the number: " number
				read -p "Enter the exponent: " exp
				declare -i result=1
				for (( i = 1; i <= exp; i++ ))
				do
					result=$(expr $result \* $number)
				done
				echo "$number power $exp is $result"
		;;
		'e' )	break
		;;
		* ) 	echo "Invalid choice"
		;;
	esac
done
