// Link: https://leetcode.com/problems/find-the-array-concatenation-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    long long findTheArrayConcVal(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n / 2; i++)
        {
            string concatenated = to_string(nums[i]) + to_string(nums[n - 1 - i]);
            ans += stoll(concatenated);
        }
        if (n % 2 == 1)
        {
            ans += nums[n / 2];
        }
        return ans;
    }
};
