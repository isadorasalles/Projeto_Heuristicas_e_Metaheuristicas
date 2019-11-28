#!/usr/bin/env bash

otimo=(12 17 29 33 24 26 68 34 16 80 44 57 15 13 44 55 55 65 75 40 16 11 27 126 345 1100 12 65 94 8 25 36 11 44 62)
declare -i i=0
for file in test_data/*
do
	./a.out $file ${otimo[i]} 1 100
	i=$((i + 1))
done
