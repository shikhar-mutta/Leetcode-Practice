// Link: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(1).
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        bitset<101> s;
        vector<int> res;
        for (int num : nums)
        {
            if (s.test(num) != 0)
                res.push_back(num);
            else
                s.set(num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
