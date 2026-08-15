// Link: https://leetcode.com/problems/reverse-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: two-pointer swap from both ends
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) swap(s[l++], s[r--]);
    }
};
