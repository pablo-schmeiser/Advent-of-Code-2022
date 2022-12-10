#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int toPriority(char c) {
    if (islower(c)){
        return (int) c - 96;
    } else {
        return (int) c - 38;
    }
}

int solutionOne() {
    ifstream myfile("input.txt");
    string line;
    int_fast32_t sum = 0;
    if (myfile.is_open()) {
        // Read the file line by line
        while (getline(myfile, line)) {
            // Split the string in the middle
            string front = line.substr(0, line.length() / 2);
            string back = line.substr(line.length() / 2);
            // Check for shared characters
            for (char c: back) {
                if (front.find(c) != string::npos) {
                    // Add the priority of the character to the sum
                    sum += toPriority(c);
                    break;
                }
            }

        }
        cout << sum << endl;
        myfile.close();
    } else {
        cout << "Unable to open file";
    }
}

int solutionTwo() {
    ifstream myfile("input.txt");
    string line;
    int_fast32_t sum = 0;
    if (myfile.is_open()) {
        // Read the file line by line
        queue<string> group;
        while (getline(myfile, line)) {
            //Add the line to the group
            group.push(line);
            if (group.size()>=3) {
                string firstLine = group.front();
                group.pop();
                string secondLine = group.front();
                group.pop();
                string thirdLine = group.front();
                group.pop();

                queue<char> firstSelection;
                // Check for shared characters
                for (char c: firstLine) {
                    if (secondLine.find(c) != string::npos) {
                        // Add the character to the queue
                        firstSelection.push(c);
                    }
                }

                while (!firstSelection.empty()) {
                    if (thirdLine.find(firstSelection.front()) != string::npos) {
                        // Add the priority of the character to the sum
                        sum += toPriority(firstSelection.front());
                        break;
                    }
                    firstSelection.pop();
                }
            }
        }
        cout << sum << endl;
        myfile.close();
    } else {
        cout << "Unable to open file";
    }
}

int main() {
    solutionOne();
    solutionTwo();
}