#!/bin/bash

set -eu

read -p "Beginner/Open + Year (Beginner 2021): " CONTEST
read -p "Number of Problems [9]: " NUMBER_OF_PROBLEMS
NUMBER_OF_PROBLEMS=${NUMBER_OF_PROBLEMS:-9}

CP_PATH=~/Google\ Drive/OmMahesh/Programming/Templates/Comp\ Prog/

mkdir "$CONTEST"
cd "$CONTEST"

letters=( 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' )
for (( i = 0; i < $NUMBER_OF_PROBLEMS; i++ )); do

  NUM=$((i+1))
  LETTER="${letters[$i]}"
  HEADER="CodeSprint $CONTEST: Problem $LETTER"

  cp -R "$CP_PATH" "Q$NUM"
  sed -i '' "s/HEADER/$HEADER/" "Q$NUM/main.cpp"

done
