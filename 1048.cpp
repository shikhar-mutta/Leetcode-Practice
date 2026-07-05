// Link: https://leetcode.com/problems/longest-string-chain/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        // Process shortest first; best[w] = longest chain ending at w.
        // Each word's predecessors = w with one char deleted (L options),
        // so lookup is O(n*L^2) total instead of O(n^2) pair checks.
        sort(words.begin(), words.end(),
             [](const string &a, const string &b) { return a.size() < b.size(); });
        unordered_map<string, int> best;
        int ans = 1;
        for (auto &w : words)
        {
            int cur = 1;
            for (int i = 0; i < (int)w.size(); i++)
            {
                string pred = w.substr(0, i) + w.substr(i + 1);
                auto it = best.find(pred);
                if (it != best.end())
                    cur = max(cur, it->second + 1);
            }
            best[w] = cur;
            ans = max(ans, cur);
        }
        return ans;
    }
};
