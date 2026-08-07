// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m)  SC: O(1)
// Approach: use std::string::find (naive scan is fine at these constraints)
class Solution {
public:
    int strStr(string haystack, string needle) {
        auto pos = haystack.find(needle);
        return pos == string::npos ? -1 : (int)pos;
    }
};
