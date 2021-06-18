#!/bin/bash

set -eu

read -p "Contest ID (1234): " CONTEST_ID
read -p "Problem Letter (A): " PROBLEM
read -p "Problem Name (Heck You): " PROBLEM_NAME

FILE_NAME="$CONTEST_ID$PROBLEM.cpp"
HEADER="CodeForces Contest $CONTEST_ID, Problem $PROBLEM: \"$PROBLEM_NAME\""
CP_PATH=~/Google\ Drive/OmMahesh/Programming/Templates/Comp\ Prog/main.cpp

cp "$CP_PATH" "$FILE_NAME"
sed -i '' "s/HEADER/$HEADER/" "$FILE_NAME"
