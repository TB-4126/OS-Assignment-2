Created by Thomas Bond

Date: April 26th 2025

Github: TB-4126

Assignment 2

# Banker's Algorithm

Submission for Assignment 2 of Dr. Qiang Guan's CS 33211 Operating Systems course.
Intended as an implementation of Banker's Algorithm.

The program was designed to be run in a Linux environment. The intended compiler is gcc.

## Project Layout

The src folder contains all the source code.
- resource.hpp
- resource.cpp
- bankers.cpp

The data folder is where any files containing data should be placed.
Must be entered as a CSV file format.
Currently contains:
- test_process.csv  : containing the data of which resources a process is requesting
- test_resource.csv : containing the data of which resources are available

## Compilation Instructions

The process can be compiled and ran by using the build.sh file.
Simply type in ./build.sh

It is also possible to type the commands out manually:
- gcc ./src/resource.cpp ./src/bankers.cpp -Wall -o bankers
- ./bankers data/test_resources.csv data/test_process.csv
