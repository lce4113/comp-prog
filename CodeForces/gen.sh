#!/bin/bash

set -eu

read -p "Contest Name: " DIR_NAME
read -p "Number of Problems [6]: " NUMBER_OF_PROBLEMS
NUMBER_OF_PROBLEMS=${NUMBER_OF_PROBLEMS:-6}

CP_PATH=~/Google\ Drive/OmMahesh/Programming/Templates/Comp\ Prog/
HEADER="CodeForces $DIR_NAME: Problem "

mkdir "$DIR_NAME"
cd "$DIR_NAME"

letters=( 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' )
for (( i = 0; i < $NUMBER_OF_PROBLEMS; i++ )); do
  NUM=$((i+1))
  LETTER="${letters[$i]}"
  cp -R "$CP_PATH" "Q$NUM"
  sed -i '' "s/HEADER/$HEADER$LETTER/" "Q$NUM/main.cpp"
done
