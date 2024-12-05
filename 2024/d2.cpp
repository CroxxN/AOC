#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int sgn(int x){
  if (x < 0) return -1;
  else if (x > 0) return 1;
  else return 0;
}


bool des_comp(int a, int b) { return (a > b); }

int part_one(ifstream *file) {
  string line;
  string token;
  int res = 0;
  bool temp = true;
  while (getline(*file, line)) {
    vector<int> values;
    stringstream ss(line);
    while (ss >> token) {
      values.push_back(stoi(token));
    }
    bool sorted = is_sorted(values.begin(), values.end()) ||
                  is_sorted(values.begin(), values.end(), des_comp);
    if (sorted) {
      for (int i = 0; i < values.size() - 1; i++) {
        if (abs(values[i] - values[i + 1]) < 1 ||
            abs(values[i] - values[i + 1]) > 3 || values[i] == values[i + 1])
          temp = false;
      }
      if (temp)
        res++;
      temp = true;
    }
  }
  return res;
}

int part_two(ifstream *file) {

  string line;
  string token;
  int res = 0;
  int temp = 0;
  int equal = 0;
  while (getline(*file, line)) {
    vector<int> values;
    stringstream ss(line);
    while (ss >> token) {
      values.push_back(stoi(token));
    }
    int sign = sgn(values[0] - values[1]);

    if (sign != sgn(values[1] - values[2]))
      if (sign != sgn(values[2] - values[3]))
        sign = sgn(values[1] - values[2]);

    bool sorted = is_sorted(values.begin(), values.end()) ||
                  is_sorted(values.begin(), values.end(), des_comp);
    if (sorted) {
      for (int i = 0; i < values.size() - 1; i++) {
        if (abs(values[i] - values[i + 1]) < 1 ||
            abs(values[i] - values[i + 1]) > 3 || values[i] == values[i + 1])
          temp++;
        else if(values[i] == values[i+1])
          equal++;
      }
      if (temp == 0)
        res++;
      else if (temp == 0 && equal == 1) res++;
      temp = 0;
    }
    for (int i = 0; i < values.size() - 1; i++) {
      if (abs(values[i] - values[i + 1]) < 1 ||
          abs(values[i] - values[i + 1]) > 3 ){}
    }
  }


    // for (int i = 0; i < values.size() - 1; i++) {
    //   if (abs(values[i] - values[i + 1]) < 1 ||
    //       abs(values[i] - values[i + 1]) > 3 )
    //     temp++;
    //   if (values[i] == values[i + 1])
    //     equal++;
    //   if (temp > 2 || equal > 1) break;
    // }


  return res;

  // if (temp <= 2) {
  //   for (int i = 0; i < values.size() - 2; i++) {
  //     if (temp == 1 && temp == equal) {
  //       if (values[i] == values[i + 1])
  //         res++;
  //     } else if (sign == sgn(values[i] - values[i + 1]) &&
  //                abs(values[i] - values[i + 1]) > 3)
  //       if (abs(values[i] - values[i + 2]) < 4)
  //         res++;
  //   }
  // }
}

int main() {
  ifstream file("d2.txt");
  // cout << part_one(&file) << endl;
  cout << part_two(&file) << endl;
  return 0;
}
