#!/bin/bash
Files=$(find -name "*.cpp")
g++ -o "SFCoding" -g3 -std=c++11 $Files -Wall -Wextra -Wold-style-cast
