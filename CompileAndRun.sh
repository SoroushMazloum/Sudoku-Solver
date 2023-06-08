#!/bin/bash
echo "Compiling"
g++ main.cpp -o main.o
chmod +x main.o
./main.o
