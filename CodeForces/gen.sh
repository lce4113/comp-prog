#!/bin/bash

set -eu

DIR_NAME=$1
CP_PATH=~/Google\ Drive/OmMahesh/Programming/Templates/Comp\ Prog/

mkdir "$DIR_NAME"
cd "$DIR_NAME"

for (( i = 1; i <= 6; i++ )); do
  cp -R "$CP_PATH" "Q$i"
done
