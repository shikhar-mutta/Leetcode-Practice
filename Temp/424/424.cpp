// Link: https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: sliding window; window is valid if (window size - max freq char
// count) <= k; shrink from left when invalid (window never actually shrinks
// net size, just slides, since we only care about the max length seen)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int left = 0, maxFreq = 0, best = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            maxFreq = max(maxFreq, ++count[s[right] - 'A']);
            while (right - left + 1 - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
