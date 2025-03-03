#!/bin/bash

# Read sentence from user
read -p "Enter a sentence: " sentence

# Count vowels
vowel_count=$(echo "$sentence" | grep -o -i "[aeiou]" | wc -l)

# Print the count
echo "Number of vowels: $vowel_count"
