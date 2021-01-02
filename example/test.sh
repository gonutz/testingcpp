#!/bin/bash

g++ test_main.cpp -o "test"
if [ $? -eq 0 ]
then
	./test
	rm "test"
fi

