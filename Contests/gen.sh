#!/usr/bin/env bash

set -eu

read -p "Contest Name (Round #720): " CONTEST
read -p "Number of Problems [6]: " NUMBER_OF_PROBLEMS
NUMBER_OF_PROBLEMS=${NUMBER_OF_PROBLEMS:-6}

mkdir "$CONTEST"
cd "$CONTEST"
touch "main.in"

CP_PATH=~/Google\ Drive/OmMahesh/Programming/Comp\ Prog/Templates/std\ io

letters=( 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' )
for (( i = 0; i < $NUMBER_OF_PROBLEMS; i++ )); do

  NUM=$((i+1))
  LETTER="${letters[$i]}"
  FILE_NAME="${LETTER,,}"
  HEADER="// CodeForces $CONTEST: Problem $LETTER"

  touch "$FILE_NAME.cpp"
  echo "$HEADER" > "$FILE_NAME.cpp"

done
