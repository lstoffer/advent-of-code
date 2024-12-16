#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

namespace y2024::t02 {

    std::vector<std::vector<int>> readInput(const std::string& path) {

        std::ifstream file(path);

        std::vector<std::vector<int>> reports;

        std::string line;
        while(std::getline(file, line)) {
            std::istringstream stream(line);

            std::vector<int> report;

            int number;
            while(stream >> number) {
                report.push_back(number);
            }

            reports.push_back(report);

        }

        return reports;

    }

    std::pair<int, std::vector<int>> isSafe(const std::vector<int>& report) {

        bool increasing = false;
        bool decreasing = false;

        int errors = 0;
        std::vector<int> errorIndices = {0};

        for(int i = 1; i < report.size(); i++) {
            if(report[i] > report[i-1]) {
                increasing = true;
            }
            else if(report[i] < report[i-1]) {
                decreasing = true;
            }
            else {
                errors ++;
                errorIndices.push_back(i);
            }

            if(increasing && decreasing) {
                errors++;
                errorIndices.push_back(i);
            }

            if(std::abs(report[i] - report[i-1]) > 3) {
                errors++;
                errorIndices.push_back(1);
            }

        }

        return std::make_pair(errors, errorIndices);

    }

    void partOne(const std::vector<std::vector<int>>& reports) {

        int safeReports = 0;

        for (const auto& report : reports) {

            if(isSafe(report).first == 0) {
                safeReports++;
            }

        }

        std::cout << "Safe Reports: " << safeReports << std::endl;

    }

    void partTwo(const std::vector<std::vector<int>>& reports) {

        int safeReports = 0;

        for(const auto& report : reports) {
            auto reportResult = isSafe(report);
            if(reportResult.first == 0) {
                safeReports++;
                continue;
            }
            else if(reportResult.first > 0) {
                
                for(auto index : reportResult.second) {

                    auto copyVector = report;
                    copyVector.erase(copyVector.begin() + index);
                    auto testResult = isSafe(copyVector);

                    if(testResult.first == 0) {
                        safeReports++;
                        break;
                    }

                }

                // for(int i = 0; i < report.size(); i++) {
                //     auto copyVector = report;
                //     copyVector.erase(copyVector.begin() + i);
                //     auto testResult = isSafe(copyVector);

                //     if(testResult.first == 0) {
                //         safeReports++;
                //         break;
                //     }
                // }
            }
        }

        std::cout << "Safe Reposts (incl. correted): " << safeReports << std::endl;

    }

    void solve() {

        const std::string path = "/home/lucst/Documents/git/private/advent-of-code/src/2024/02/input.txt";

        const auto& input = readInput(path);

        partOne(input);
        partTwo(input);


    }

}




