#!/usr/bin/env bash

for file in test_data/*
do
	./ilsvnd $file 
	
done
