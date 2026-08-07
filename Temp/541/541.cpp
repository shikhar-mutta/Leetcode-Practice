// Link: https://leetcode.com/problems/reverse-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) extra
// Approach: for every 2k block, reverse the first k characters
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < (int)s.size(); i += 2 * k) {
            int end = min(i + k, (int)s.size());
            reverse(s.begin() + i, s.begin() + end);
        }
        return s;
    }
};
