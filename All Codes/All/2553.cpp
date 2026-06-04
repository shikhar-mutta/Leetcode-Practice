// Link: https://leetcode.com/problems/separate-the-digits-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m). SC: O(n*m).
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> ans;
        for (int num : nums)
        {
            string s = to_string(num);
            for (char c : s)
            {
                ans.push_back(c - '0');
            }
        }
        return ans;
    }
};
