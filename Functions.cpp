#include "Functions.h"
#include <iostream>
#include <random>
#include <string>
#include <sstream>
#ifdef _WIN32
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

void GenerateNumberVector(std::vector<int>& NumberVector) {
    NumberVector.clear();

    for (int i = 0; i <= 74; i++)
        NumberVector.push_back(i + 1);
}

void PullNumber(std::vector<int>& NumberVector) {
    static std::mt19937 mt(__rdtsc());
    std::string pull;

    // Our function to get random numbers, changes to match the size of our vector minus one.
    std::uniform_int_distribution<> num(0, NumberVector.size() - 1);

    int numPos = num(mt);
    int numVal = NumberVector.at(numPos);

    pull = "Call " + std::to_string(76 - NumberVector.size()) + ": ";

    AddBingoLetter(numVal,pull);

    std::cout << pull;

    NumberVector.erase(NumberVector.begin() + numPos);
}

void CheckNums(const std::vector<int>& NumberVector) {
    std::string inputString = " ";
    int inputInteger;
    bool found;
    bool validInput;

    std::cout << "\nType each number without the letter and press enter to check if it's been called.\n"
                 "Enter nothing to quit.\n";

    while (!inputString.empty()) {
        validInput = false;
        found = false;

        do {
            std::cout << "Enter a number: ";
            std::getline(std::cin, inputString);

            if (inputString.empty())
                return;

            std::stringstream inputStream(inputString);

            inputStream >> inputInteger;

            if (inputInteger > 75 || inputInteger < 1)
                std::cout << "Please enter a valid number\n";
            else
                validInput = true;
        } while (!validInput);

        for (auto i : NumberVector)
            if (inputString == std::to_string(i)) {
                found = true;
            }

        if (found)
            std::cout << "Number has not been called!\n\n";
        else
            std::cout << "Number has been called!\n\n";
    }

}

void DisplayUncalledNums(const std::vector<int>& NumberVector) {
    std::cout << "\nUncalled numbers:\n";

    for (auto i : NumberVector) {
        std::string j;
        AddBingoLetter(i, j);
        std::cout << j << std::endl;
    }
}

void AddBingoLetter(const int& number, std::string& string) {
    if (number > 0 && number <= 15)
        string += "B-" + std::to_string(number);
    else if (number >= 16 && number <= 30)
        string += "I-" + std::to_string(number);
    else if (number >= 31 && number <= 45)
        string += "N-" + std::to_string(number);
    else if (number >= 46 && number <= 60)
        string += "G-" + std::to_string(number);
    else
        string += "O-" + std::to_string(number);
}

