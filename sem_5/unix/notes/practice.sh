alias files = `ls -l|grep ^-|sort -k5|tr -s ' '|cut -d ' ' -f5,9|tail -5`

# alias => short name
# ls -l => all files
# grep ^- => regular files
# sort -k5 => sort based on 5th field
# tr -s ' ' => translate(tr) sqeeze(-s) extra spaces
# cut -d ' ' -f5,9 give the 5th and 9th field
# tail -5 => give the last 5 entries


umask

# default permissions for a newly created files

# Default permission for 
                        # User Group Others
    # directories are - 777
    # files are -       666

# 4-read
# 2-write
# 1-execute

# We should subtract 022

# 777-022 = 755
# 666-022 = 644

umask 0000 # change the default file permissions

history # commands executed in the past

.bash_history # contains all prev commands

# iterating through a commands' output
for i in `ls`
do
    echo "hai $i"
done

# ps commands give processes
# system admins write shell scripts which iterate through 
# the processes and do some action

