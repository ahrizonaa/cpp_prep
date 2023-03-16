//
//  functions.cpp
//  grokking-patterns
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
    sentence = std::regex_replace(sentence, std::regex("^ +| +$|( ) +"), "$1");
    std::reverse(sentence.begin(), sentence.end());
    
    std::cout << sentence << std::endl;
    
    // "We love python"
    
    for (std::string::iterator start = sentence.begin(); start < sentence.end() - 1; start++) {
        std::string::iterator end = start + 1;
        
        std::cout << "start=" << *start << "; end=" << *end << ";" << std::endl;
        
        while (*end != ' ' && end < sentence.end()) {
            end += 1;
        }
        std::reverse(start, end);
        start = end;

        std::cout << *start << std::endl;

    }
    
    return sentence;
}
/*
 abbababa
 bbababa - no
 abababa - yes
 abababa - yes
 abbbaba - no
 abbaaba - no
 abbabba - yes
 abbabaa - no
 abbabab - no
*/
