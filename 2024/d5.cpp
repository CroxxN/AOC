#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int part_one(ifstream *f) {
  string line;
  unordered_map<int, vector<int>> m;
  int res = 0;
  bool swtch = true;

  while (getline(*f, line)) {
  // while (getline(bruh, line)) {

    if (line.empty()) {
      swtch = false;
      continue;
    }
    if (swtch) {
      string sub = line.substr(0, 2);
      int first = stoi(sub);
      sub = line.substr(3, 2);
      int second = stoi(sub);

      m[first].push_back(second);
    } else {
      vector<int> values;
      int mid = 0;
      bool found = false;
      for (int i = 0; i < line.length(); i += 3) {
        int num = stoi(line.substr(i, 2));
        values.push_back(num);
      }
      for (int i = 0; i < values.size(); i++) {
        for (int j = i + 1; j < values.size(); j++) {
          for (auto x : m[values[j]]) {
            if (x == values[i])
              found = true;
          }
        }
      }
      if (!found) {
        res += values[values.size() / 2];
      }
    }
  }
  return res;
}

int part_two(ifstream *f) {
  string line;
  unordered_map<int, vector<int>> m;
  int res = 0;
  bool swtch = true;

  while (getline(*f, line)) {
  // while (getline(bruh, line)) {

    if (line.empty()) {
      swtch = false;
      continue;
    }
    if (swtch) {
      string sub = line.substr(0, 2);
      int first = stoi(sub);
      sub = line.substr(3, 2);
      int second = stoi(sub);

      m[first].push_back(second);
    } else {
      vector<int> values;
      int mid = 0;
      bool found = false;
      for (int i = 0; i < line.length(); i += 3) {
        int num = stoi(line.substr(i, 2));
        values.push_back(num);
      }
      for (int i = 0; i < values.size(); i++) {
        for (int j = i + 1; j < values.size(); j++) {
          for (auto x : m[values[j]]) {
            if (x == values[i]){
              int temp = values[i];
              values[i] = values[j];
              values[j] = temp;
              found = true;
            }
              
          }
        }
      }
      if (found) {
        res += values[values.size() / 2];
      }
    }
  }
  return res;
}

int main() {
  ifstream f("d5.txt");
  cout << part_two(&f) << endl;
  // cout << part_one(&f) << endl;
}
