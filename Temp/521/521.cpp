// Link: https://leetcode.com/problems/longest-uncommon-subsequence-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: if the strings are equal, no uncommon subsequence exists;
// otherwise the longer string itself is uncommon (can't be a subsequence
// of the shorter/equal one unless identical)
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        return max(a.size(), b.size());
    }
};
