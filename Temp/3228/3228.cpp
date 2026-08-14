// Link: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        vector<pair<char,int>> blocks;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            blocks.push_back({s[i], j - i});
            i = j;
        }
        int m = blocks.size();
        vector<int> suffixZero(m + 1, 0);
        for (int k = m - 1; k >= 0; k--) {
            suffixZero[k] = suffixZero[k+1] + (blocks[k].first == '0' ? 1 : 0);
        }
        long long ans = 0;
        for (int k = 0; k < m; k++) {
            if (blocks[k].first == '1') {
                ans += (long long)blocks[k].second * suffixZero[k+1];
            }
        }
        return (int)ans;
    }
};
