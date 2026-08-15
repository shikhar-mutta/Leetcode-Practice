// Link: https://leetcode.com/problems/design-phone-directory/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized per operation  SC: O(maxNumbers)
// Approach: set of available numbers + set of used numbers
class PhoneDirectory {
    set<int> available;
    unordered_set<int> used;

public:
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i++) available.insert(i);
    }

    int get() {
        if (available.empty()) return -1;
        int num = *available.begin();
        available.erase(num);
        used.insert(num);
        return num;
    }

    bool check(int number) {
        return available.count(number) > 0;
    }

    void release(int number) {
        if (used.erase(number)) available.insert(number);
    }
};
