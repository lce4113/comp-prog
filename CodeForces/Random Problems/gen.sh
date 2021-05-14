#!/bin/bash

set -eu

read -p "Contest ID: " CONTEST_ID
read -p "Contest Name: " CONTEST_NAME
read -p "Problem Letter: " PROBLEM

FILE_NAME="$CONTEST_ID$PROBLEM.cpp"
HEADER="CodeForces $CONTEST_NAME: Problem $PROBLEM"
CP_PATH=~/Google\ Drive/OmMahesh/Programming/Templates/Comp\ Prog/main.cpp

cp "$CP_PATH" "$FILE_NAME"
sed -i '' "s/HEADER/$HEADER/" "$FILE_NAME"
