// Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(k)
// Approach: sliding window with a frequency map, shrink from the left while
// distinct char count exceeds k
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        unordered_map<char, int> freq;
        int left = 0, best = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            freq[s[right]]++;
            while ((int)freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
