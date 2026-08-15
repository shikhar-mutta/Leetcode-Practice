// Link: https://leetcode.com/problems/repeated-substring-pattern/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: s is made of repeated substrings iff s is a substring of
// (s+s) with the first and last char removed
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = (s + s).substr(1, 2 * s.size() - 2);
        return doubled.find(s) != string::npos;
    }
};
