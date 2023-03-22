#include <iostream>
#include <algorithm>

std::string toBinary(char c);

int main() {
    std::string input;

    std::cout << "Convert text to binary: " ;
    getline(std::cin, input);

    std::cout << "Result binary: " << std::endl;
    for (char c : input) {
        if(!std::isspace(c))
            std::cout << toBinary(c) << " ";
    }

    return 0;
}

std::string toBinary(char c){
    int ascii = static_cast<int>((unsigned char )c); // Convert char to ASCII value
    int quotient = ascii;
    int r;
    std::string binary;

    // Convert ASCII value to binary
    while (quotient > 0) {
        r = quotient % 2;
        quotient = quotient / 2;
        binary += std::to_string(r);
    }

    // Pad binary string with leading zeroes if necessary
    while (binary.length() < 8) {
        binary.append("0");
    }

    // Reverse the binary string
    reverse(binary.begin(), binary.end());
    return binary;
}