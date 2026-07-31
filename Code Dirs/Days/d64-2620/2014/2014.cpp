// Link: https://leetcode.com/problems/longest-subsequence-repeated-k-times/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(26^m * n)  SC: O(n + m)
//  Approach: Use DFS to generate all possible subsequences of the string s. For each generated subsequence, check if it can be formed by repeating it k times in s. Keep track of the longest valid subsequence found during the DFS traversal. Use a frequency array to limit the number of times each character can be used in the subsequence based on its frequency in s divided by k.
class Solution
{
public:
    string s, ans;
    int k;
    vector<int> lim;
    int remain;

    bool check(const string &t)
    {
        if (t.empty())
            return true;
        int j = 0, cnt = 0;
        for (char ch : s)
        {
            if (ch == t[j])
            {
                j++;
                if (j == (int)t.size())
                {
                    cnt++;
                    if (cnt == k)
                        return true;
                    j = 0;
                }
            }
        }
        return false;
    }

    void dfs(string &cur)
    {
        if (!cur.empty() && !check(cur))
            return;

        if (cur.size() > ans.size() ||
            (cur.size() == ans.size() && cur > ans))
        {
            ans = cur;
        }

        if ((int)cur.size() + remain <= (int)ans.size())
            return;

        for (int c = 25; c >= 0; c--)
        {
            if (lim[c] == 0)
                continue;

            lim[c]--;
            remain--;
            cur.push_back(char('a' + c));

            dfs(cur);

            cur.pop_back();
            remain++;
            lim[c]++;
        }
    }

    string longestSubsequenceRepeatedK(string s, int k)
    {
        this->s = s;
        this->k = k;

        vector<int> freq(26, 0);
        for (char ch : s)
            freq[ch - 'a']++;

        lim.assign(26, 0);
        remain = 0;
        for (int i = 0; i < 26; i++)
        {
            lim[i] = freq[i] / k;
            remain += lim[i];
        }

        string cur = "";
        dfs(cur);
        return ans;
    }
};