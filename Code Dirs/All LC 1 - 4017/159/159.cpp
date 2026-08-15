// Link: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) (at most 3 chars in the window map at once)
// Approach: sliding window with a char->last-seen-count map; shrink from the left whenever a third
// distinct character enters the window
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> count;
        int left = 0, best = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            count[s[right]]++;
            while (count.size() > 2) {
                count[s[left]]--;
                if (count[s[left]] == 0) count.erase(s[left]);
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
