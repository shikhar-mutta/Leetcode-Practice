// Link: https://leetcode.com/problems/add-digits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: digital root formula — 0 if num is 0, else 1 + (num-1) % 9
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};
