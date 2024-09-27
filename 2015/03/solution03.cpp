//
// Created by lucst on 27/09/24.
//

#include <fstream>
#include <iostream>
#include <string>
#include <set>

enum class INPUT_MODE {
    ALL = 0,
    EVEN = 1,
    ODD = 2
};

int deliverPackages(std::string input, std::set<std::pair<int, int>>& corSet, INPUT_MODE inputMode) {

    std::pair<int, int> currCor;

    corSet.insert(currCor);


    int visitedHouses = 1;
    int inputIndex = 1;

    for(const char& c : input) {

        if((inputMode == INPUT_MODE::ODD && inputIndex%2 == 0) || (inputMode == INPUT_MODE::EVEN && inputIndex%2 != 0)) {
            inputIndex++;
            continue;
        }

        std::pair<int, int> newCor;

        switch(c) {
            case '^':
                newCor.first = currCor.first + 1;
                newCor.second = currCor.second;
                break;
            case 'v':
                newCor.first = currCor.first - 1;
                newCor.second = currCor.second;
                break;
            case '>':
                newCor.first = currCor.first;
                newCor.second = currCor.second + 1;
                break;
            case '<':
                newCor.first = currCor.first;
                newCor.second = currCor.second - 1;
                break;
            default:
                break;
        }

        currCor = newCor;

        if(corSet.find(newCor) == corSet.end()) {
            corSet.insert(newCor);
            visitedHouses++;
        }

        inputIndex++;

    }

    return visitedHouses;
}


int main() {

    std::ifstream file("/home/lucst/Documents/git/private/advent-of-code/2015/03/input.txt");

    std::string input;

    if (file.is_open()) {
        std::getline(file, input);
        file.close();
    }

    std::set<std::pair<int, int>> corSetOne;
    std::set<std::pair<int, int>> corSetTwo;

    const int partOne = deliverPackages(input, corSetOne, INPUT_MODE::ALL);
    std::cout << "Part I - Number of vistied hosues: " << partOne << std::endl;

    int partTwo = deliverPackages(input, corSetTwo, INPUT_MODE::ODD);
    partTwo += deliverPackages(input, corSetTwo, INPUT_MODE::EVEN) - 1;

    std::cout << "Part II - Number of vistied hosues: " << partTwo << std::endl;

    return 0;
}