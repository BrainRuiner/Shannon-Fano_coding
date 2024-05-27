#!/bin/bash
g++ -g3 -std=c++11 ./*.cpp -o ./${PWD##*/} -Wall -Wextra -Wold-style-cast
