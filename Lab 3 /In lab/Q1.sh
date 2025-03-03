#!/bin/bash

# Check if exactly 2 arguments are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 num1 num2"
    exit 1
fi

# Multiply the two numbers
result=$(( $1 * $2 ))

# Print the result
echo "Multiplication result: $result"
