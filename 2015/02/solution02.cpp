//
// Created by lucst on 26/09/24.
//


#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

void partOne(std::vector<std::string>& lines) {

    int paperSum = 0;
    int ribbonSum = 0;

    for(const std::string& line : lines) {

        std::stringstream ss(line);

        std::string token;
        std::vector<int> sizes;

        while(std::getline(ss, token, 'x')) {
            sizes.push_back(std::stoi(token));
        }

        const int l = sizes[0];
        const int w = sizes[1];
        const int h = sizes[2];

        const int frontBack = w*h;
        const int leftRight = h*l;
        const int topBottom = l*w;

        const int extraPaper = std::min(std::min(frontBack,leftRight),topBottom);

        const int paper = extraPaper + 2*frontBack + 2*leftRight + 2*topBottom;

        paperSum += paper;


        int longestSide = std::max(std::max(l,w), h);
        int ribbon = (l+w+h-longestSide)*2;

        int extraRibbon = l*w*h;
        ribbon += extraRibbon;

        ribbonSum += ribbon;
    }

    std::cout << "Papiermenge: " << paperSum << std::endl;
    std::cout << "Bandlaenge: " << ribbonSum << std::endl;

}


int main() {
    std::ifstream file("/home/lucst/Documents/git/private/advent-of-code/2015/02/input.txt");

    std::vector<std::string> lines;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
    }

    partOne(lines);

    return 0;

}