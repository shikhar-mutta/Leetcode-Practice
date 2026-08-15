// Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for (char c : allowed) mask |= (1 << (c - 'a'));
        int count = 0;
        for (auto& w : words) {
            bool ok = true;
            for (char c : w) {
                if (!(mask & (1 << (c - 'a')))) { ok = false; break; }
            }
            if (ok) count++;
        }
        return count;
    }
};
