// Link: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> res;
        for (int i = 0; i < (int)s.size(); i += k)
        {
            string g = s.substr(i, k);
            g.resize(k, fill); // pad the last group up to length k
            res.push_back(g);
        }
        return res;
    }
};
