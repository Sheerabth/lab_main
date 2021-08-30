#!/bin/sh

if [ $# -ne 1 ]
then
        echo "Enter valid number of arguments"
        exit 1
fi

case $1 in
        [0-9][0-9]* )
                echo "Its a number"
                ;;
        [a-z] )
                echo "Its a lower case letter"
                ;;
        [A-Z] )
                echo "Its a upper case letter"
                ;;
        [a-zA-z0-9\ ]* )
                echo "Enter single character"
                ;;
        * )
                echo "Special character"
                ;;