#!/usr/bin/env bash

set -eu

read -p "Year + Contest + Division (2021 December Silver): " CONTEST
read -p "File IO [No]? " FILE_IO
FILE_IO=${FILE_IO:-No}

mkdir "$CONTEST"
cd "$CONTEST"

CP_PATH=~/Google\ Drive/OmMahesh/Programming/Comp\ Prog/Templates/std\ io

letters=( 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' )
for (( i = 0; i < 3; i++ )); do

  NUM=$((i+1))
  LETTER="${letters[$i]}"
  DIR_NAME="Q$NUM"
  FILE_NAME="${LETTER,,}"
  HEADER="USACO $CONTEST: Problem $LETTER"

  cp -R "$CP_PATH" "$DIR_NAME"
  mv "$DIR_NAME/main.cpp" "$DIR_NAME/$FILE_NAME.cpp"
  sed -i '' "s/HEADER/$HEADER/" "$DIR_NAME/$FILE_NAME.cpp"

  if [ $FILE_IO == "Yes" ]; then
    sed -i '' "s/stdIO();/fileIO(\"FILE_NAME\");/" "$DIR_NAME/$FILE_NAME.cpp"
  fi

done
