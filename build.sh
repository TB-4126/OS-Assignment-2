#!/bin/bash
set -eu

#Run by typing ./build.sh
#Script for compiling the code with gcc
# -o file : outputs am executable named 'file'

#Compilation
echo "Compiling Process..."

gcc ./src/resource.cpp ./src/bankers.cpp -Wall -o bankers

#Running the Executables

echo "Running..."

./bankers data/test_resource.csv data/test_process.csv
