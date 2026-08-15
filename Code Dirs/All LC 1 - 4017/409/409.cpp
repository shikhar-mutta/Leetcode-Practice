// Link: https://leetcode.com/problems/longest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: use each char's count rounded down to even; allow one leftover
// odd-count char in the middle
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        int length = 0;
        bool hasOdd = false;
        for (auto& [c, cnt] : freq) {
            length += cnt / 2 * 2;
            if (cnt % 2) hasOdd = true;
        }
        return length + (hasOdd ? 1 : 0);
    }
};
