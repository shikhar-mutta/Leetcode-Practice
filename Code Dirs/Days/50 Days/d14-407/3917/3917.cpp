// Link: https://leetcode.com/problems/count-indices-with-opposite-parity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)  SC: O(n)
    vector<int> countOppositeParity(vector<int> &nums)
    {
        int even = 0, odd = 0, n = nums.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--)
            if (nums[i] % 2 == 0)
            {
                ans[i] = odd;
                even++;
            }
            else
            {
                ans[i] = even;
                odd++;
            }
        return ans;
    }
};
