#!/bin/bash

# Check if directory path is given
if [ $# -ne 1 ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

dir=$1
backup_dir="backup_$(date +%Y%m%d_%H%M%S)"

# Check if the directory exists
if [ ! -d "$dir" ]; then
    echo "Error: Directory $dir does not exist."
    exit 1
fi

# Create backup directory
mkdir -p "$backup_dir"

# Copy files to backup directory
cp -r "$dir"/* "$backup_dir"

# Count files and directories
file_count=$(find "$backup_dir" -type f | wc -l)
dir_count=$(find "$backup_dir" -type d | wc -l)

echo "Backup completed successfully!"
echo "Backup folder: $backup_dir"
echo "Files backed up: $file_count"
echo "Directories backed up: $dir_count"
