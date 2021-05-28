#!/bin/bash

set -eu

read -p "Contest ID (1234): " CONTEST_ID
read -p "Problem Name (Heck You): " CONTEST_NAME
read -p "Problem Letter (A): " PROBLEM

FILE_NAME="$CONTEST_ID$PROBLEM.cpp"
HEADER="CodeForces \"$CONTEST_NAME\": Problem $PROBLEM"
CP_PATH=~/Google\ Drive/OmMahesh/Programming/Templates/Comp\ Prog/main.cpp

cp "$CP_PATH" "$FILE_NAME"
sed -i '' "s/HEADER/$HEADER/" "$FILE_NAME"
