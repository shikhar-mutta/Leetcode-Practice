// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(min(n, charset))
// Approach: sliding window with last-seen-index map; shrink left edge past any repeat
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> last;
        int best = 0, left = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            if (last.count(c) && last[c] >= left) left = last[c] + 1;
            last[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
