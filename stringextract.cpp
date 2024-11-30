#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double extractNumeric(const string&str) {
    bool isValidNumber = true;
    bool isNegative = false;
    bool hasDecimal = false;
    //Checks if string is positive
    if (str[0] == '-') {
            isNegative = true;
        }
    //Long while loop to ensure string is valid.
    int i = 0;
    while (i < str.length()) {
        //Ensures string is numbers only
        if (str[i] != '0' || str[i] != '1' || str[i] != '2' || str[i] != '3' ||
        str[i] != '4' || str[i] != '5' || str[i] != '6' || str[i] != '7'  || 
        str[i] != '8' || str[i] != '9' || str[i] != '+' || str[i] != '-' || str[i] != '.') {
            isValidNumber = false;
        }
        //Checks if there is a + or - in the wrong position
        if((str[i] != '+' || str[i] != '-') && (i != 0)) {
            isValidNumber = false;
        }
        //Checks if the number has a decimal in it
        if(str[i] == '.') {
            hasDecimal = true;
        }
    }
    if(isValidNumber == true) {
        
    } else {
        //If answer is not valid, return this number.
        return -999999.99;
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