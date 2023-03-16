#include <iostream>
#include "Classes.hpp"
#include <vector>
using namespace std;

bool is_even(int n) {
    return (n % 2 == 0);
}

int main(int argc, const char * argv[]) {
    vector<int> v{1,2,3,4};
    
    int x{42};
    auto num_even = count_if(v.begin(), v.end(),
     [x] (int n) {
        return (n % 2 == 0);
    });
    
    cout << num_even << endl;
    cout << x << endl;
    return 0;
}
