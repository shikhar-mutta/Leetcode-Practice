// Link: https://leetcode.com/problems/number-of-good-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++; // count the frequency of each number
        }
        int ans = 0;
        for (auto i : m)
        {
            ans += (i.second * (i.second - 1)) / 2; // nC2
        }
        return ans;
    }
};
