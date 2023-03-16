//
//  functions.cpp
//  cpp_playground
//
//  Created by Mark Garcia on 3/11/23.
//

#include "functions.hpp"

bool sumOfThree(std::vector<int> nums, int target) {
    std::vector<int>::iterator low, high;
    std::sort(nums.begin(), nums.end());
    for (auto i = nums.begin(); i < nums.end(); i++) {
        low = i + 1;
        high = nums.end() - 1;
        
        while (low < high) {
            int sum = *i + *low + *high;
            std::cout << "i = " << *i << " low = " << *low << " high = " << *high << std::endl;
            if (sum == target) {
                return true;
            } else if (sum > target) {
                high -= 1;
            } else {
                low += 1;
            }
        }
    }
    
    return false;
}

std::string reverseWordsInString(std::string sentence) {
    return sentence;
}
