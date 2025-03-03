#!/bin/bash

# Read filename or directory from user
read -p "Enter the file/directory name: " name

# Check if it exists
if [ -e "$name" ]; then
    if [ -f "$name" ]; then
        echo "$name is a file."
    elif [ -d "$name" ]; then
        echo "$name is a directory."
    fi
    ls -l "$name"  # Display details
else
    echo "$name does not exist."
fi
