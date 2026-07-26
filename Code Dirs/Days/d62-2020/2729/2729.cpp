// Link: https://leetcode.com/problems/check-if-the-number-is-fascinating/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: concatenate n, 2n, 3n as strings; fascinating iff the result is
// exactly 9 digits long (rules out any leading-zero digit sneaking in via a
// shorter concatenation) and, once sorted, forms "123456789" (each digit 1-9
// exactly once).
class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2 * n) + to_string(3 * n);
        if (s.size() != 9)
            return false;
        sort(s.begin(), s.end());
        return s == "123456789";
    }
};
