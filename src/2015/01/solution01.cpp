//
// Created by lucst on 26/09/24.
//

#include <iostream>
#include <fstream>
#include "2015/01/solution01.hpp"

namespace y2015::t01 {

    void partOne(const std::string& path) {
        std::ifstream file(path);

        int up = 0;
        int down = 0;

        if (file.is_open()) {
            std::string line;
            std::getline(file, line);
            file.close();

            for (const char c : line) {
                if(c == '(') {
                    up++;
                }
                else if(c == ')') {
                    down++;
                }
            }
        }
        else {
            std::cout << "Unable to open file" << std::endl;
        }

        std::cout << "Result: " << up - down << std::endl;
    }

    void partTwo(const std::string& path) {

        std::ifstream file(path);

        if (file.is_open()) {
            std::string line;
            std::getline(file, line);
            file.close();

            int floor = 0;
            int position = 1;

            for (const char c : line) {
                if(c == '(') {
                    floor++;
                }
                else if(c == ')') {
                    floor--;
                }

                if(floor < 0) {
                    std::cout << "Position that reaches basement is: " << position << std::endl;
                    break;
                } else {
                    position++;
                }
            }
        }
        else {
            std::cout << "Unable to open file" << std::endl;
        }
    }

    int solve() {
        const std::string filePath = "/home/lucst/Documents/git/private/advent-of-code/2015/01/input.txt";

        partOne(filePath);
        partTwo(filePath);

        return 0;
    }

}




