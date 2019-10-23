#!/bin/bash
export PYTHONHASHSEED=0;
cd Codes/;
for filename in *; do
	if [ -d "$filename" ]; then
		for cppfile in "$filename"/*; do
			python3 hasher.py "$cppfile" > ../Hashed/"$cppfile";
		done
	else
		python3 hasher.py "$filename" > ../Hashed/"$filename";
	fi
done
