//
//  main.cpp
//  grokking-patterns
//
//  Created by Mark Garcia on 3/11/23.
//

#include <iostream>

#include "functions.hpp"

void hasDuplicates() {
    std::vector<int> nums = { 1,2,2,3,4,5,5,5,6,7 };
    std::unordered_set<int> numset;
    
    bool result = false;
    
    for (auto &e : nums) {
        if (numset.contains(e)) {
            result = true;
            break;
        }
        numset.insert(e);
    }
    
    std::cout << "hasDuplicates() -> " << result << std::endl;
    
    std::cout << std::endl;
    
    return;
}

void fizzBuzz() {
    std::vector<std::string> results;
    int n = 15;
    
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0)
            results.push_back("fizz");
        else if (i % 5 == 0)
            results.push_back("buzz");
        else
            results.push_back(std::to_string(i));
    }
    
    for (auto &e : results) {
        std::cout << "fizzbuzz() -> " <<  e << std::endl;
    }
    
    std::cout << std::endl;
    
    return;
}

void numberOfIslands() {
    
    return;
}

int sumDigits(int number) {
    int sum = 0;
    while (number > 0) {
        int digit = number % 10;
        number = std::floor(number / 10);
        sum += digit * digit;
    }
    return sum;
}

bool isHappyNumber(int n) {
    int slowptr = n;
    int fastptr = sumDigits(n);
    
    while (fastptr != 1 && slowptr != fastptr) {
        slowptr = sumDigits(slowptr);
        fastptr = sumDigits(sumDigits(fastptr));
    }
    
    if (fastptr == 1)
        return true;
    else
        return false;
}

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }
    
    void Prepend(Node* node) {
        if (head != nullptr) {
            node->next = head;
            head = node;
        } else {
            head = node;
        }
    }
    
    void CreateFromArray(std::vector<int>& vec) {
        for (int i = (int)vec.size() - 1; i >= 0; i--) {
            Node* node = new Node(vec[i]);
            Prepend(node);
        }
        return;
    }
    
    int Length(Node* head) {
        Node* tmp = head;
        int length = 0;
        while (tmp != nullptr) {
            length += 1;
            tmp = tmp->next;
        }
        return length;
    }
    
    Node* GetNode(Node* head, int pos) {
        if (pos != -1) {
            int p = 0;
            Node* ptr = head;
            while (p < pos) {
                ptr = ptr->next;
                p += 1;
            }
            return ptr;
        }
        return head;
    }
};

bool DetectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    int i = 0, j = 0, space1 = 0, space2 = 2, last = 5;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        last -= 2;
        i += 1;
        j += 2;
        
        if (!fast) {
            break;
        }
        if (slow == fast) {
            return true;
        } else {
            if (last == -1)
                space2 += 2;
            if (last == -3)
                space2 += 2;
        }
    }
    return false;
}

int NextStep(std::vector<int> arr, int currentidx, bool currentDirection) {
    int size = (int)arr.size();
    
    bool nextDirection = false;
    
    if (arr[currentidx] >= 0)
        nextDirection = true;
    
    if (nextDirection != currentDirection || abs(arr[currentidx] % size) == 0)
        return -1;
    
    int findStep = currentidx + arr[currentidx];
    findStep = (((findStep % size) + size) % size);
    return findStep;
}

bool CircularArrayLoop(std::vector<int> arr) {
    bool currentDirection = false;
    for (int i = 0; i < (int)arr.size(); i++) {
        if (abs(arr[i]) == arr.size())
            continue;
        if (arr[i] >= 0)
            currentDirection = true;
        else
            currentDirection = false;
        int slowptr = i;
        int fastptr = i;
        
        while (slowptr != fastptr || slowptr != -1 || fastptr != -1) {
            slowptr = NextStep(arr, fastptr, currentDirection);
            if (slowptr == -1)
                break;
            
            fastptr = NextStep(arr, fastptr, currentDirection);
            if (fastptr != -1)
                fastptr = NextStep(arr, fastptr, currentDirection);
            if (slowptr == fastptr || fastptr == -1)
                break;
        }
        if (slowptr == fastptr && slowptr != -1)
            return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {

    hasDuplicates();
    
    fizzBuzz();
    
    numberOfIslands();
    
    isHappyNumber(4);
    
    return 0;
}
