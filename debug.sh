#!/bin/bash
rm ./.proj/* >> /dev/null 2>&1
cp ./rcs/*.h ./.proj/ >> /dev/null 2>&1
cp ./rcs/*.hpp ./.proj/ >> /dev/null 2>&1
cp ./src/*.cpp ./.proj/ >> /dev/null 2>&1
g++ -g3 -std=c++11 ./.proj/*.cpp -o ./bin/${PWD##*/} -Wall -Wextra -Wold-style-cast
