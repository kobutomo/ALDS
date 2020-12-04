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
#define OPTIMIZE_STDIO ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed
#define endl '\n'

void solve(istream &cin, ostream &cout) {
  int ans;

  ////////////////////////////////
  //                            //
  //   Write your answer here.  //
  //                            //
  ////////////////////////////////

  cout << ans << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
}
#endif
EOS
)

# test file template
test_template=$(
  cat <<EOS
#define TEST
#include "main.cpp"

#include <dirent.h>

void Tab(int n) {
  for (int i = 0; i < n; i++) {
    cout << "\t";
  }
}

string Blue(string s) {
  return "\033[34m" + s + "\033[m";
}

string Green(string s) {
  return "\033[32m" + s + "\033[m";
}

string Magenta(string s) {
  return "\033[35m" + s + "\033[m";
}

string Red(string s) {
  return "\033[31m" + s + "\033[m";
}

string BGRed(string s) {
  return "\033[41m" + s + "\033[m";
}

string Under(string s) {
  return "\033[4m" + s + "\033[m";
}

string Yellow(string s) {
  return "\033[33m" + s + "\033[m";
}

int sample_num(string path) {
  int n = 0;
  struct dirent *de;

  DIR *d = opendir(path.c_str());
  while ((de = readdir(d))) {
    string file = de->d_name;
    if (file.find("input") != string::npos) {
      n++;
    }
  }
  closedir(d);
  return n;
}

int main() {
  OPTIMIZE_STDIO;

  int tn;

  string path = __FILE__;
  path = path.substr(0, path.find_last_of('/'));

  tn = sample_num(path);

  for (int i = 1; i <= tn; i++) {
    if (i > 1) {
      cout << endl;
    }
    vector<string> po, ao;

    string s;
    ostringstream oss;

    string input = path + "/" + to_string(i) + "_input.txt";

    ifstream pifs(input);
    ifstream aifs(path + "/" + to_string(i) + "_output.txt");

    auto start = chrono::system_clock::now();
    solve(pifs, oss);
    auto end = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    pifs.clear();
    pifs.seekg(0, ios_base::beg);

    istringstream iss(oss.str());

    while (iss >> s) {
      po.push_back(s);
    }

    while (aifs >> s) {
      ao.push_back(s);
    }

    ostringstream ss;
    ss << i;
    cout << Green("Testing " + ss.str()) << " ...  ";
    if (po.size() == ao.size() && equal(po.cbegin(), po.cend(), ao.cbegin())) {
      cout << Blue("OK") << "    " << time << " [ms]" << endl;
    } else {
      cout << Red("NG") << "    " << time << " [ms]" << endl;
      Tab(1);
      cout << Magenta("Input") << endl;
      while (getline(pifs, s)) {
        Tab(2);
        cout << s << endl;
      }

      Tab(1);
      cout << Magenta("Your Answer") << endl;
      Tab(2);
      for (int i = 0; i < po.size(); i++) {
        if (i != 0) {
          cout << " ";
        }
        if (i < ao.size() && po[i] == ao[i]) {
          cout << po[i];
        } else {
          cout << Red(po[i]);
        }
      }
      if (po.size() < ao.size()) {
        cout << " ";
        cout << BGRed(" ");
      }
      cout << endl;

      Tab(1);
      cout << Magenta("Right Answer") << endl;
      Tab(2);
      for (int i = 0; i < ao.size(); i++) {
        if (i != 0) {
          cout << " ";
        }
        cout << ao[i];
      }
      cout << endl;
    }
  }
}
EOS
)

touch main.cpp
echo "$template" >>./main.cpp
echo "Created main.cpp"
touch test.cpp
echo "$test_template" >>./test.cpp
echo "Created test.cpp"
touch 1_input.txt
echo "Created input.txt"
touch 1_output.txt
echo "Created output.txt"

cd ..

# Write settings into CMakeLists.txt
echo "" >>./CMakeLists.txt

echo "add_executable(${fullname}_main $fullname/main.cpp)" >>./CMakeLists.txt
echo "add_executable(${fullname}_test $fullname/test.cpp)" >>./CMakeLists.txt

echo "Modified CMakeLists.txt"
