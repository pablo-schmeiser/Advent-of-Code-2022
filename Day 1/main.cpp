#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ifstream myfile ("input.txt");
    string line;

    if (myfile.is_open()) {
        priority_queue<int> q;
        int_fast32_t sum = 0;
        // Read the file line by line
        while (getline(myfile, line)) {
            // Check for next elf
            if (line == "") {
                // Add the sum of the current elf's calories to the priority queue
                q.push(sum);
                sum = 0;
            } else {
                // Add the calories of an elf
                sum += stoi(line);
            }
        }
        // Clear the sum variable to reuse it
        sum = 0;
        for (int_fast32_t i = 0; i < 3; i++) {
            sum += q.top();
            q.pop();
        }
        // Print the result
        cout << sum << endl;
        myfile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}