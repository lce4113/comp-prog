#!/bin/bash

set -eu

read -p "Novice/Advanced + Year: " DIR_NAME
read -p "Number of Problems [9]: " NUMBER_OF_PROBLEMS
NUMBER_OF_PROBLEMS=${NUMBER_OF_PROBLEMS:-9}

CP_PATH=~/Google\ Drive/OmMahesh/Programming/Templates/Comp\ Prog/
HEADER="ProCo $DIR_NAME: Problem "

mkdir "$DIR_NAME"
cd "$DIR_NAME"

letters=( 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' )
for (( i = 0; i < $NUMBER_OF_PROBLEMS; i++ )); do
  NUM=$((i+1))
  LETTER="${letters[$i]}"
  cp -R "$CP_PATH" "Q$NUM"
  sed -i '' "s/HEADER/$HEADER$LETTER/" "Q$NUM/main.cpp"
done
