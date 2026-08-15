// Link: https://leetcode.com/problems/ransom-note/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m)  SC: O(1) (26 letters)
// Approach: count magazine letters, decrement for each ransom note letter
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for (char c : magazine) count[c - 'a']++;
        for (char c : ransomNote) {
            if (--count[c - 'a'] < 0) return false;
        }
        return true;
    }
};
