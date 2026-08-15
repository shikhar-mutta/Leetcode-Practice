// Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int mx = 0, mn = INT_MAX;
                for (int c = 0; c < 26; c++) {
                    if (freq[c] > 0) {
                        mx = max(mx, freq[c]);
                        mn = min(mn, freq[c]);
                    }
                }
                total += mx - mn;
            }
        }
        return total;
    }
};
