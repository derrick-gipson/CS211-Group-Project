#include "luhn.h"
#include <cctype>

bool isValidFormat(const std::string& input, std::string& errorMsg) {
    if (input.length() != 16) {
        errorMsg = "Error: Input must be exactly 16 characters long.";
        return false;
    }
    for (char c : input) {
        if (!std::isdigit(c)) {
            errorMsg = "Error: Input contains non-digit characters.";
            return false;
        }
    }
    return true;
}

bool checkLuhn(const std::string& number) {
    int sum = 0;
    bool doubleDigit = false;

    // Traverse from right to left
    for (int i = 15; i >= 0; --i) {
        int digit = number[i] - '0';

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }

        sum += digit;
        doubleDigit = !doubleDigit; // Toggle for every second digit
    }

    return (sum % 10 == 0);
}
