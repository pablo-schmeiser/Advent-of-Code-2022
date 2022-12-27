//
// Created by Pablo Schmeiser on 23.12.2022.
//
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
string[] split (string str, char seperator) {
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    string strings[2];
    while (i <= str.size()) {
        if (str[i] == seperator || i == str.size()) {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
    return strings;
}

string[] split (string strs[], char seperator) {
    string strings[4] = {};
    int_fast16_t i = 0;
    int_fast16_t j = 0;
    for (string str : strings){
        strings[i] = split(str, seperator)[j];
        i++;
        j++;
        if (j % 2 == 0) {
            j = 0;
        }
    }
    return strings;
}

int solutionOne() {
    ifstream myfile("input.txt");
    string line;
    int_fast32_t sum = 0;
    string separators = ",-";
    if (myfile.is_open()) {
        // Read the file line by line
        while (getline(myfile, line)) {
             vector<string> strings = split(split(line, separators[0]), separators[1]);
             if (stoi(strings[0]) <= stoi(strings[2]) && stoi(strings[1]) >= stoi(strings[3])) {
                 sum++;
             } else if (stoi(strings[0]) >= stoi(strings[2]) && stoi(strings[1]) <= stoi(strings[3])) {
                 sum++;
             }
        }
        cout << sum << endl;
        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    return 0;
}

int main() {
    return solutionOne();
}