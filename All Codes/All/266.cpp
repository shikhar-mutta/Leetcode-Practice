// Link: https://leetcode.com/problems/palindrome-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) (fixed 128-entry array)
// Approach: count char frequencies; a permutation can be a palindrome iff at most one char has an odd count
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int count[128] = {0};
        for (char c : s) count[(unsigned char)c]++;
        int odd = 0;
        for (int c : count) if (c % 2) odd++;
        return odd <= 1;
    }
};
