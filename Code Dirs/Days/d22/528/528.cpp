// Link: https://leetcode.com/problems/random-pick-with-weight/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> prefix; // prefix[i] = w[0] + ... + w[i]
    int total;
    mt19937 rng;

public:
    Solution(vector<int> &w) : rng(random_device{}())
    {
        prefix.resize(w.size());
        int run = 0;
        for (int i = 0; i < (int)w.size(); ++i)
        {
            run += w[i];
            prefix[i] = run;
        }
        total = run;
    }

    int pickIndex()
    {
        int target = (int)(rng() % (unsigned)total) + 1;
        // find the first index i such that prefix[i] >= target
        return (int)(lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin());
    }
};
