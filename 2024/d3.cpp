#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;

int part_one(ifstream *f) {
  long long res = 0;
  stringstream buf;
  buf << f->rdbuf();
  string s = buf.str();
  string comp("mul(");
  for (int i = 0; i < s.length() - 7; i++) {
  // for (int i = 0; i < 50; i++) {
    string sub = s.substr(i, 4);
    string ints;
    string seconds;
    int k = i + 4;
    if (!sub.compare(comp)) {
      for (int j = i + 4; j <= i + 7; j++) {
        if (s[j] == ',')
          break;
        else {
          if (s[j] - 48 >= 0 && s[j] - 48 <= 9)
            ints.push_back(s[j]);
          else
            continue;
        }
        k++;
      }
      if (ints.empty())
        continue;
      int first = stoi(ints);
      int h = k+1;
      for (int j = k+1; j <= k + 3; j++) {
        if (s[j] == ',')
          break;
        else {
          if (s[j] - 48 >= 0 && s[j] - 48 <= 9)
            seconds.push_back(s[j]);
          else
            continue;
        }
        h++;
      }

      if (seconds.empty())
        continue;
      if (s[h] != ')')
        continue;
      int second = stoi(seconds);
      res += (first * second);
    }
  }
  return res;
}

int part_two(ifstream *f){
  
  long long res = 0;
  stringstream buf;
  buf << f->rdbuf();
  string s = buf.str();
  string comp("mul(");
  string dos("do()");
  string donts("don't()");
  bool doe = true;
  for (int i = 0; i < s.length() - 7; i++) {
  // for (int i = 0; i < 50; i++) {
    string sub = s.substr(i, 4);
    string nub = s.substr(i, 7);
    if (!sub.compare("do()")) doe = true;
    if (!nub.compare("don't()")) doe = false;
    string ints;
    string seconds;
    int k = i + 4;
    if (!doe) continue;
    if (!sub.compare(comp)) {
      for (int j = i + 4; j <= i + 7; j++) {
        if (s[j] == ',')
          break;
        else {
          if (s[j] - 48 >= 0 && s[j] - 48 <= 9)
            ints.push_back(s[j]);
          else
            continue;
        }
        k++;
      }
      if (ints.empty())
        continue;
      int first = stoi(ints);
      int h = k+1;
      for (int j = k+1; j <= k + 3; j++) {
        if (s[j] == ',')
          break;
        else {
          if (s[j] - 48 >= 0 && s[j] - 48 <= 9)
            seconds.push_back(s[j]);
          else
            continue;
        }
        h++;
      }

      if (seconds.empty())
        continue;
      if (s[h] != ')')
        continue;
      int second = stoi(seconds);
      res += (first * second);
    }
  }
  return res;
}

int main() {
  ifstream f("d3.txt");
  // cout << part_one(&f) << endl;
  cout << part_two(&f) << endl;
}
