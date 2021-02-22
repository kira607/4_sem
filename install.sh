#!/bin/bash

declare -a subjects=(
'programming' 
'optimization' 
'computer_orgranization' 
'english' 
'math_logic' 
'theory_of_probability'
)

if [ "$1" == "-u" ]; then
    for subject in "${subjects[@]}"; do 
        echo "removing $subject directory";
        rm -rf $subject
    done;
    rm .gitignore
    echo "uninstall completed"
    exit 0
fi

for subject in "${subjects[@]}"; do 
    echo "creating $subject directory";
    mkdir $subject
    cd $subject
    touch .meta
    echo "materials for '$subject' subject" > .meta
    cd ../
done;

touch .gitignore
echo "install.sh" > .gitignore
exit 0
