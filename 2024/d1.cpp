#include <algorithm>
#include <fstream>
#include<iostream>

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int part_one(ifstream* file){
    
    string line;
    vector<int> first;
    vector<int> second;
    while (getline(*file, line)){
        int delim = line.find(' ');
        auto fr = stoi(line.substr(0, delim));
        auto sc = stoi(line.substr(delim+1, line.length()));
        first.push_back(fr);
        second.push_back(sc);
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    int diff = 0;


    for (size_t i=0; i < first.size(); i++){
         int d = abs(first[i] - second[i]);
         diff+=d;
    }
    return diff;
}

int part_two(ifstream *file){
    
    string line;
    vector<int> first;
    vector<int> second;
    unordered_map<int, int> m;
    int res = 0;

    while (getline(*file, line)){
        int delim = line.find(' ');
        auto fr = stoi(line.substr(0, delim));
        auto sc = stoi(line.substr(delim+1, line.length()));
        first.push_back(fr);
        second.push_back(sc);
    }
    for (size_t i=0; i<second.size(); i++) 
        m[second[i]]++;
    
    for (size_t i=0; i<first.size(); i++){
        int mul = m[first[i]];
        int r = first[i] * mul;
        res += r;
    }
    return res;
}

int main(){
    ifstream file("d1.txt");
    cout << part_two(&file) << endl;
}
