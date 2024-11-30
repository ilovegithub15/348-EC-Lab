#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double extractNumeric(const string&str) {
    //Initalizes several needed bools.
    bool isValidNumber = true;
    bool isNegative = false;
    bool hasDecimal = false;
    bool hasSignAtStart = false;
    //Checks if string is positive
    if (str[0] == '-') {
            isNegative = true;
            hasSignAtStart = true;
        }
    if (str[0] == '+') {
            hasSignAtStart = true;
        }
    //Long while loop to ensure string is valid.
    int i = 0;
    while (i < str.length()) {
        //Ensures string is numbers only
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' &&
        str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7'  && 
        str[i] != '8' && str[i] != '9' && str[i] != '+' && str[i] != '-' && str[i] != '.') {
            isValidNumber = false;
        }
        //Checks if there is a + or - in the wrong position
        if((str[i] == '+' || str[i] == '-') && (i != 0)) {
            isValidNumber = false;
        }
        i++;
    }
    //If number is valid, start creating new number to return.
    if(isValidNumber == true) {
        double result = 0.0;
        int decimalPlace = 1;
        int j = 0;
        //If there is a sign at the start, instead start the index at 1.
        if(hasSignAtStart == true) {
            j = 1;
        }
        for (; j < str.length(); j++) {
            char ch = str[j];
            if(ch != '.') {
                //Adds the number in the correct spot
                result = result * 10 + (ch - '0');
                //Changes the spot of the decimal if it has one
                if (hasDecimal) {
                    decimalPlace *= 10;
                }
            } else {
                hasDecimal = true;
            }
        }
        //If there is a decimal, it divides the number by a factor of 10 to place it correctly
        if (hasDecimal) {
            result /= decimalPlace;
        }
        if (isNegative) {
            result = -result;
        }
        return result;
    } else {
        //If answer is not valid, return this number which will read as invalid.
        return -999999.99;
    }
    

}
//Main function
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