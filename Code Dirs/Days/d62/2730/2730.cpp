// Link: https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: sliding window tracking the count of adjacent-equal pairs inside
// it. Extend right, incrementing the pair count on a new adjacent duplicate;
// while more than one such pair exists, shrink from the left (decrementing the
// pair count whenever the removed element was itself part of an adjacent
// duplicate pair). Track the max window length seen.
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int left = 0, ans = 1;
        int pairs = 0;
        for (int right = 1; right < n; right++) {
            if (s[right] == s[right - 1])
                pairs++;
            while (pairs > 1) {
                if (left + 1 < n && s[left] == s[left + 1])
                    pairs--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
