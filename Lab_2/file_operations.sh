#!/bin/bash
file_name="my_file.txt"
touch "$file_name"
chmod 644 "$file_name"
echo "Hello, Bash!">"$file_name"

echo "Содержимое файла $file_name:"
cat "$file_name"
rm --f  "$file_name" 


