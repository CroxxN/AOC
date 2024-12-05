#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int part_one(ifstream *f) {
  string line;
  vector<string> lines;
  int res = 0;
  while (getline(*f, line)) {
    lines.push_back(line);
  }

  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].length(); j++) {
      string sub = lines[i].substr(j, 4);
      if (i < lines.size() - 3)
        if (lines[i][j] == 'X' && lines[i + 1][j] == 'M' &&
            lines[i + 2][j] == 'A' && lines[i + 3][j] == 'S') {
          res++;
        }
      if (i < lines.size() - 3)
        if (lines[i][j] == 'S' && lines[i + 1][j] == 'A' &&
            lines[i + 2][j] == 'M' && lines[i + 3][j] == 'X') {
          res++;
        }
      if (j < lines[i].size() - 3)
        if (lines[i][j] == 'X' && lines[i][j + 1] == 'M' &&
            lines[i][j + 2] == 'A' && lines[i][j + 3] == 'S') {
          res++;
        }
      if (j < lines[i].size() - 3)
        if (lines[i][j] == 'S' && lines[i][j + 1] == 'A' &&
            lines[i][j + 2] == 'M' && lines[i][j + 3] == 'X') {
          res++;
        }

      if (i < lines.size() - 3 && j < lines[i].length() - 3)
        if (lines[i][j] == 'X' && lines[i + 1][j + 1] == 'M' &&
            lines[i + 2][j + 2] == 'A' && lines[i + 3][j + 3] == 'S') {
          res++;
        }
      if (i < lines.size() - 3 && j < lines[i].length() - 3)
        if (lines[i][j] == 'S' && lines[i + 1][j + 1] == 'A' &&
            lines[i + 2][j + 2] == 'M' && lines[i + 3][j + 3] == 'X') {
          res++;
        }

      if (i < lines.size() - 3 && j < lines[i].length() - 3)
        if (lines[i + 3][j] == 'X' && lines[i + 2][j + 1] == 'M' &&
            lines[i + 1][j + 2] == 'A' && lines[i][j + 3] == 'S') {
          res++;
          cout << i << " " << j << endl;
        }
      if (i < lines.size() - 3 && j < lines[i].length() - 3)
        if (lines[i + 3][j] == 'S' && lines[i + 2][j + 1] == 'A' &&
            lines[i + 1][j + 2] == 'M' && lines[i][j + 3] == 'X') {
          res++;
        }
    }
  }
  return res;
}

int part_two(ifstream *f) {

  string line;
  vector<string> lines;
  int res = 0;
  while (getline(*f, line)) {
    lines.push_back(line);
  }

  for (int i = 0; i < lines.size()-2; i++) {
    for (int j = 0; j < lines[i].length()-2; j++) {
      if (lines[i+1][j + 1] == 'A') {
        if (lines[i][j] == 'M' && lines[i+2][j+2] == 'S' && lines[i][j+2] == 'M' && lines[i+2][j] == 'S'){
          res++;
        }
        if (lines[i][j] == 'S' && lines[i+2][j+2] == 'M' && lines[i][j+2] == 'M' && lines[i+2][j] == 'S'){
          res++;
        }
        if (lines[i][j] == 'S' && lines[i+2][j+2] == 'M' && lines[i][j+2] == 'S' && lines[i+2][j] == 'M'){
          res++;
        }
        if (lines[i][j] == 'M' && lines[i+2][j+2] == 'S' && lines[i][j+2] == 'S' && lines[i+2][j] == 'M'){
          res++;
        }
      }
    }
  }
  return res;
}

int main() {
  ifstream f("d4.txt");
  cout << part_two(&f) << endl;
  // cout << part_one(&f) << endl;
}
