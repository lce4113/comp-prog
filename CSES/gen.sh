#!/bin/bash

set -eu

read -p "Problem Name: " PROBLEM_NAME

CP_PATH=~/Google\ Drive/OmMahesh/Programming/Comp\ Prog/Templates/std\ io
# HEADER="CSES $PROBLEM_NAME"
HEADER="// CSES $PROBLEM_NAME"

# cp -R "$CP_PATH" "$PROBLEM_NAME"
# sed -i '' "s/HEADER/$HEADER/" "$PROBLEM_NAME/main.cpp"
mkdir "$PROBLEM_NAME"
touch "$PROBLEM_NAME/main.cpp"
echo "$HEADER" > "$PROBLEM_NAME/main.cpp"
touch "$PROBLEM_NAME/main.in"
