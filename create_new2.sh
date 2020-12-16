#!/bin/bash

cd $(dirname $0)
dir=$(pwd)

echo $dir

# コース名
prefix=$1
# 問題名
name=$2

fullname=${prefix}_${name}

if [ -d $fullname ]; then
  echo "Directory already exists."
  exit 1
fi

echo "Create problem directory..."
mkdir $fullname
cd $fullname

# cpp file template
template=$(
  cat <<EOS
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {

  ////////////////////////////////
  //                            //
  //   Write your answer here.  //
  //                            //
  ////////////////////////////////

}
EOS
)

touch main.cpp
echo "$template" >>./main.cpp
echo "Created main.cpp"

cd ..

# Write settings into CMakeLists.txt
echo "" >>./CMakeLists.txt

echo "add_executable(${fullname} $fullname/main.cpp)" >>./CMakeLists.txt

echo "Modified CMakeLists.txt"
