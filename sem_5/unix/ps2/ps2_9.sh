trap exit_func SIGINT

exit_func() {
    printf "\nExiting the program.....\n"
    exit
}

while [ true ]
do
    echo "THANK YOU"
    sleep 40
done