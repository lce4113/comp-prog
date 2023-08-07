#!/usr/bin/env bash

set -eu

read -p "Year + Contest + Division (2021 December Silver): " CONTEST

mkdir "$CONTEST"
cd "$CONTEST"

letters=( 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' )
for (( i = 0; i < 3; i++ )); do

  NUM=$((i+1))
  LETTER="${letters[$i]}"
  DIR_NAME="Q$NUM"
  FILE_NAME="${LETTER,,}"
  HEADER="// USACO $CONTEST: Problem $LETTER"

  mkdir "$DIR_NAME"
  touch "$DIR_NAME/$FILE_NAME.cpp"
  echo "$HEADER" > "$DIR_NAME/$FILE_NAME.cpp"
  touch "$DIR_NAME/main.in"

done
