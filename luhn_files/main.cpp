#include <iostream>
#include <string>
#include "luhn.h"

int main() {
    std::string input;
    std::cout << "--- Luhn Checksum Validator ---\n";
    std::cout << "Enter a 16-digit number or 'exit' to quit.\n\n";

    while (true) {
        std::cout << "Input: ";
        std::getline(std::cin, input);

        if (input == "exit") {
            std::cout << "Exiting program.\n";
            break;
        }

        std::string errorMsg;
        if (!isValidFormat(input, errorMsg)) {
            std::cout << errorMsg << "\n\n";
            continue;
        }

        if (checkLuhn(input)) {
            std::cout << "Result: Checksum passes.\n\n";
        } else {
            std::cout << "Result: Checksum fails.\n\n";
        }
    }
    return 0;
}
