// Link: https://leetcode.com/problems/design-a-number-container-system/description/

#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
    unordered_map<int,int> indexToNumber;
    unordered_map<int, set<int>> numberToIndices;
public:
    NumberContainers() {}

    void change(int index, int number) {
        if (indexToNumber.count(index)) {
            int old = indexToNumber[index];
            numberToIndices[old].erase(index);
            if (numberToIndices[old].empty()) numberToIndices.erase(old);
        }
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }

    int find(int number) {
        auto it = numberToIndices.find(number);
        if (it == numberToIndices.end() || it->second.empty()) return -1;
        return *it->second.begin();
    }
};
