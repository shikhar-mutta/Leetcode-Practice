// Link: https://leetcode.com/problems/length-of-the-longest-valid-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N * 10), SC: O(sum|forbidden|)
// Approach: forbidden strings have length <= 10, so for each right endpoint only the last 10
// characters matter. Sliding window: for each right, check all suffixes (length 1..10) ending
// there against the forbidden set; if one matches, shrink the window's left edge just past it.
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> bad(forbidden.begin(), forbidden.end());
        int n = word.size();
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            int maxLen = min(10, right - left + 1);
            for (int len = 1; len <= maxLen; len++) {
                string sub = word.substr(right - len + 1, len);
                if (bad.count(sub)) {
                    left = max(left, right - len + 2);
                    break;
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
