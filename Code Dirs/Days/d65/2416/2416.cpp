// Link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(NlogN + N^2), SC: O(N)
// Approach: Sort the words and find the common prefix with the next word. Then, for each word, add its length to the answer and add the common prefix length with the next words until the common prefix becomes 0.
using ll = long long;
class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        int n = words.size();

        vector<pair<string, int>> w(n);

        for (int i = 0; i < n; i++)
        {
            w[i] = {words[i], i};
        }

        sort(w.begin(), w.end());
        vector<int> commonPrefix(n);
        for (int i = 1; i < n; i++)
        {
            auto &a = w[i - 1].first;

            auto &b = w[i].first;
            int ln = min(a.size(), b.size());
            int j = 0;
            while (j < ln && a[j] == b[j])
            {
                j++;
            }
            commonPrefix[i] = j;
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int prefix = w[i].first.size();

            ans[w[i].second] += prefix;
            for (int j = i + 1; j < n; j++)
            {
                prefix = min(prefix, commonPrefix[j]);
                if (prefix == 0)
                {
                    break;
                }
                ans[w[j].second] += prefix;
                ans[w[i].second] += prefix;
            }
        }
        return ans;
    }
};