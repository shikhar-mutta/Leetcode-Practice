// Link: https://leetcode.com/problems/valid-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: two pointers from both ends, skipping non-alphanumeric chars, comparing case-insensitively
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++; r--;
        }
        return true;
    }
};
