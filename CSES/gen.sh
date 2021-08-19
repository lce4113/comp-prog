#!/bin/bash

set -eu

read -p "Problem Name: " PROBLEM_NAME

CP_PATH=~/Google\ Drive/OmMahesh/Programming/Comp\ Prog/Templates/std\ io
HEADER="CSES $PROBLEM_NAME"

cp -R "$CP_PATH" "$PROBLEM_NAME"
sed -i '' "s/HEADER/$HEADER/" "$PROBLEM_NAME/main.cpp"
