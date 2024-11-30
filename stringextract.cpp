#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double extractNumeric(const string&str) {
    bool isValidNumber = true;
    bool isNegative = false;
    //Checks if string is positive
    if (str[0] == '-') {
            isNegative = true;
        }
    //Long while loop to ensure string is valid.
    while (i <= str.length()); {
        //Checks if string is positive
        //Ensures string is numbers only
        if (str[i] != "0" || ) {
            
        }
    }

}

int main() {
    string input;
    while(true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;
        if (input == "END") {
            break;
        }
        double number = extractNumeric(input);

        if(number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }
    return 0;
}