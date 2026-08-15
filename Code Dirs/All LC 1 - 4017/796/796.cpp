// Link: https://leetcode.com/problems/rotate-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: goal is a rotation of s iff goal is a substring of s+s (with equal lengths).
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s+s).find(goal) != string::npos;
    }
};
