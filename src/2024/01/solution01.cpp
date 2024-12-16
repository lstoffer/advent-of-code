#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

namespace y2024::t01 {

    std::pair<std::vector<int>, std::vector<int>> readInput(const std::string& path) {
        std::ifstream file(path);

        std::vector<int> left;
        std::vector<int> right;

        std::string line;
        while(std::getline(file, line)) {
            std::istringstream stream(line);

            int leftNum, rightNum;

            if(stream) {
                stream >> leftNum;
                stream >> rightNum;
            }

            left.push_back(leftNum);
            right.push_back(rightNum);

        }

        return std::make_pair(left, right);
    }
    
    void partOne(std::vector<int>& left, std::vector<int>& right) {

        int distance = 0;

        std::sort(left.begin(), left.end());
        std::sort(right.begin(), right.end());

        for(int i = 0; i < left.size(); i++) {
            int l = left[i];
            int r = right[i];

            distance += std::abs(l-r);
        }

        std::cout << "Total Distance: " << distance << std::endl;

    }

    void partTwo(std::vector<int>& left, std::vector<int>& right) {
        
        int similarity = 0;

        for(auto i : left) {
            int appearances = std::count(right.begin(), right.end(), i);
            similarity += i * appearances;
        }

        std::cout << "Similarity: " << similarity << std::endl;

    }

    void solve() {

        const std::string filePath = "/home/lucst/Documents/git/private/advent-of-code/src/2024/01/input.txt";

        auto input = readInput(filePath);
        auto left = input.first;
        auto right = input.second; 


        partOne(left, right);
        partTwo(left, right);

    }

}