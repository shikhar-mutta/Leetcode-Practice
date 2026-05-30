// Link: https://leetcode.com/problems/binary-prefix-divisible-by-5/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        vector<bool> ans;
        int cnt = 0;
        for (auto it : nums)
        {
            // 2^n % 5 = 1, so we can just keep track of the remainder mod 5
            cnt = (cnt * 2 + it) % 5;
            if (cnt % 5 == 0) // if the remainder is 0, then the number is divisible by 5
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
