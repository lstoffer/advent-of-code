//
// Created by lucst on 14/12/24.
//

#ifndef SOLUTION03_HPP
#define SOLUTION03_HPP

#include <string>
#include <set>

namespace y2015::t03 {

    enum class INPUT_MODE {
        ALL = 0,
        EVEN = 1,
        ODD = 2
    };

    int deliverPackages(std::string input, std::set<std::pair<int, int>>& corSet, INPUT_MODE inputMode);
    int solve();

}

#endif //SOLUTION03_HPP
