#!/bin/bash
rm Text.txt
touch Text.txt 
g++ main.cpp -o main1.exe
./main1.exe

echo "/n"
cat Text.txt
