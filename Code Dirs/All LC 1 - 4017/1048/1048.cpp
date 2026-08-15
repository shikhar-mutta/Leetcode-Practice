// Link: https://leetcode.com/problems/longest-string-chain/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        unordered_map<string,int> dp;
        int best = 1;
        for (auto& w : words) {
            dp[w] = 1;
            for (int i = 0; i < (int)w.size(); i++) {
                string pred = w.substr(0, i) + w.substr(i+1);
                if (dp.count(pred)) dp[w] = max(dp[w], dp[pred] + 1);
            }
            best = max(best, dp[w]);
        }
        return best;
    }
};
