// Link: https://leetcode.com/problems/h-index/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for (int c : citations)
        {
            if (c >= n)
                count[n]++;
            else
                count[c]++;
        }
        int h = 0;
        for (int i = n; i >= 0; --i)
        {
            h += count[i];
            if (h >= i)
                return i;
        }
        return 0;
    }
};
