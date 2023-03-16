//
//  main.cpp
//  cpp_playground
//
//  Created by Mark Garcia on 3/10/23.
//

#include <iostream>

#include "functions.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string s = "mark";
    
    std::string::iterator start = s.begin(), end = s.end();
    int i = 1, j = s.size();
    bool limit_reached = false;
    while (start < end) {
        if (*start == *end) {
            continue;
        } else if (!limit_reached) {
            limit_reached = true;
            std::string s1 = s.substr(0, i) + s.substr(i + 1);
            std::string s2 = s1;
            std::reverse(s2.begin(), s2.end());
            
            if (s1 == s2) {
                continue;
            } else {
                return 0;
            }
            continue;
        } else {
            return 0;
        }
    }
    
    
    
    return 0;
}
