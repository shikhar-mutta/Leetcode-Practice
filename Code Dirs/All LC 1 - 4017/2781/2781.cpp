// Link: https://leetcode.com/problems/length-of-the-longest-valid-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> forbiddenSet(forbidden.begin(), forbidden.end());
        int n = word.size();
        int left = 0, best = 0;
        for (int right = 0; right < n; right++) {
            for (int len = 1; len <= 10 && right - len + 1 >= left; len++) {
                string sub = word.substr(right - len + 1, len);
                if (forbiddenSet.count(sub)) {
                    left = right - len + 2;
                    break;
                }
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
