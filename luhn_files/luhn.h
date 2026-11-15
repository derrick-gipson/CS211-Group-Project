//This file defines the interface for our validation and calculation functions.
#ifndef LUHN_H
#define LUHN_H

#include <string>

// Validates that the input is exactly 16 digits
bool isValidFormat(const std::string& input, std::string& errorMsg);

// Performs the Luhn algorithm calculation
bool checkLuhn(const std::string& number);

#endif
