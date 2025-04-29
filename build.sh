#!/bin/bash
set -eu

#Run by typing ./build.sh

#Script for compiling the code with gcc
# -o file : outputs am executable named 'file'

#
#Compilation
#

#Processes
echo "Compiling Processes..."

gcc ./src/resource.cpp ./src/bankers.cpp -Wall -o bankers
gcc ./src/resource.cpp ./src/p0.cpp -Wall -o p0
gcc ./src/resource.cpp ./src/p1.cpp -Wall -o p1
gcc ./src/resource.cpp ./src/p2.cpp -Wall -o p2
gcc ./src/resource.cpp ./src/p3.cpp -Wall -o p3
gcc ./src/resource.cpp ./src/p4.cpp -Wall -o p4

echo "Compilation Complete."

#
#Running the Executables
#

#echo "Running..."

#./bankers data/test_resources.csv data/test_process.csv
#./p0 & ./p1 & ./p2 & ./p3 & ./p4
