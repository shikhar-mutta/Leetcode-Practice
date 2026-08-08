// Link: https://leetcode.com/problems/to-lower-case/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: convert each uppercase letter to lowercase.
class Solution {
public:
    string toLowerCase(string s) {
        for (char& c : s) if (c >= 'A' && c <= 'Z') c += 32;
        return s;
    }
};
