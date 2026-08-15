// Link: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> freq;
        int l = 0, ans = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            freq[s[r]]++;
            while (freq[s[r]] > 2) {
                freq[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
