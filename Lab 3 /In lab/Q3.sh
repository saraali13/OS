#!/bin/bash

# Read filename from user
read -p "Enter the filename: " filename

# Check if file exists
if [ -f "$filename" ]; then
    # Append date and time to the file
    echo "$(date)" >> "$filename"
    echo "Date and time appended to $filename"
else
    echo "File does not exist."
fi
