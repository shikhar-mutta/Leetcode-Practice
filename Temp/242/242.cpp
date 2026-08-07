// Link: https://leetcode.com/problems/valid-anagram/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) (fixed 26-entry array)
// Approach: count letter frequencies in s, subtract for t, all counts must return to 0
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;
        for (int c : count) if (c != 0) return false;
        return true;
    }
};
