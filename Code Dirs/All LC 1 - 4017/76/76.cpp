// Link: https://leetcode.com/problems/minimum-window-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n+m)  SC: O(charset)
// Approach: sliding window; expand right until all of t's chars are covered, then shrink left while still valid
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        for (char c : t) need[c]++;
        int required = need.size();
        unordered_map<char,int> window;
        int formed = 0;
        int left = 0, bestLen = INT_MAX, bestStart = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) formed++;
            while (formed == required) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }
                char lc = s[left];
                window[lc]--;
                if (need.count(lc) && window[lc] < need[lc]) formed--;
                left++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
