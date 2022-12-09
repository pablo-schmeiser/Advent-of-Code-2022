#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Used to calculate Task 1
int tableOne[3][3] {{4, 8, 3}, {1, 5, 9}, {7, 2, 6}};
// Used to calculate Task 2
int tableTwo[3][3] {{3, 4, 8}, {1, 5, 9}, {2, 6, 7}};

int main() {
    ifstream myfile ("input.txt");
    string line;
    string delimiter = " ";
    int_fast32_t sum = 0;
    if (myfile.is_open()) {
        // Read the file line by line
        while (getline(myfile, line)) {
            // Split the string in at the space
            int_fast16_t i;
            int_fast16_t j;

            // Convert the substrings to a numerical representation, with which the win matrix will be called
            for (char c : line.substr(0, 1)){
                i = (int) c - 65;
            }
            for (char c : line.substr(2, 1)){
                j = (int) c - 88;
            }
            // Sum the winnings from the winnings matrix
            sum += tableTwo[i][j];
        }
        cout << sum << endl;
        myfile.close();
    }
     else {
        cout << "Unable to open file";
    }
}