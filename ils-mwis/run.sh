#!/usr/bin/env bash

make 
for file in test_data/*
do
	./a.out $file 
	
done
make clean
