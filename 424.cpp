// Link: https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int left = 0, maxFreq = 0, best = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            maxFreq = max(maxFreq, ++cnt[s[right] - 'A']);
            // window invalid if chars to replace (size - maxFreq) exceed k
            while ((right - left + 1) - maxFreq > k) {
                cnt[s[left] - 'A']--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
