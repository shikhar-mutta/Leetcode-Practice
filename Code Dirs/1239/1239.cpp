// Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        vector<int> masks{0};
        int best = 0;
        for (auto &s : arr)
        {
            int m = 0;
            bool ok = true;
            for (char c : s)
            {
                int b = 1 << (c - 'a');
                if (m & b)
                {
                    ok = false;
                    break;
                }
                m |= b;
            }
            if (!ok)
                continue;
            int sz = masks.size();
            for (int i = 0; i < sz; ++i)
            {
                if (masks[i] & m)
                    continue;
                int comb = masks[i] | m;
                masks.push_back(comb);
                best = max(best, __builtin_popcount(comb));
            }
        }
        return best;
    }
};