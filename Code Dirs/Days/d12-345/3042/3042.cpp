// Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2 * m).  SC: O(1)
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int cnt = 0, n = words.size();
        auto isPrefixAndSuffix = [](string &s, string &p)
        {
            int n = s.size(), m = p.size();
            if (m > n)
                return false;

            for (int i = 0; i < m; i++)
            {
                // check prefix
                if (s[i] != p[i])
                    return false;
                // check suffix
                if (s[n - 1 - i] != p[m - 1 - i])
                    return false;
            }
            return true;
        };
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isPrefixAndSuffix(words[j], words[i]))
                    cnt++;
        return cnt;
    }
};
