// Link: https://leetcode.com/problems/merge-close-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) worst case SC: O(n)
// Approach: n<=100, so simulate directly: repeatedly scan the current
// string for the smallest-left (then smallest-right) pair of equal
// characters within distance k, erase the right one, and repeat until
// no such pair remains.
class Solution {
public:
    string mergeCharacters(string s, int k) {
        bool changed = true;
        while (changed) {
            changed = false;
            int n = s.size();
            for (int i = 0; i < n && !changed; i++) {
                for (int j = i + 1; j <= i + k && j < n; j++) {
                    if (s[i] == s[j]) {
                        s.erase(s.begin() + j);
                        changed = true;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
