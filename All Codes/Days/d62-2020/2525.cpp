// Link: https://leetcode.com/problems/categorize-box-according-to-criteria/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: directly apply the problem's bulky/heavy thresholds (any
// dimension >= 1e4, or volume >= 1e9, makes it bulky; mass >= 100 makes
// it heavy) and combine the two booleans into the required label.
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long volume = (long long)length * width * height;
        bool bulky = length >= 10000 || width >= 10000 || height >= 10000 ||
                     volume >= 1000000000LL;
        bool heavy = mass >= 100;

        if (bulky && heavy)
            return "Both";
        if (bulky)
            return "Bulky";
        if (heavy)
            return "Heavy";
        return "Neither";
    }
};
