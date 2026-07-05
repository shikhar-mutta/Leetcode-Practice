// Link: https://leetcode.com/problems/longest-string-chain/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*L^2), SC: O(n)
    // Approach: We can use dynamic programming to solve this problem. We can sort the input array of words based on their lengths and then use a hash map to keep track of the longest chain ending at each word. For each word, we can generate its predecessors by removing one character at a time and check if the predecessor exists in the hash map. If it does, we can update the longest chain for the current word. Finally, we return the maximum length of the longest chain found.
    int longestStrChain(vector<string> &words)
    {
        // Process shortest first; best[w] = longest chain ending at w.
        // Each word's predecessors = w with one char deleted (L options),
        // so lookup is O(n*L^2) total instead of O(n^2) pair checks.
        sort(words.begin(), words.end(),
             [](const string &a, const string &b)
             { return a.size() < b.size(); });
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
