// Link: https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;
        int target = -1;
        for (int f : freq) {
            if (f == 0) continue;
            if (target == -1) target = f;
            else if (f != target) return false;
        }
        return true;
    }
};
