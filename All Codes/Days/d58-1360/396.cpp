// Link: https://leetcode.com/problems/rotate-function/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the size of the input array. We are iterating through the array twice, once to calculate the sum of the array and once to calculate the initial value of F(0). Then we iterate through the array again to calculate F(k) for k = 1 to n-1.
    // SC: O(1) as we are using a constant amount of space to store the variables n, sum_arr, tmp, and ans.
    //  Approach:
    //  1. We can first calculate the sum of the array and the initial value of F(0) by iterating through the array once.
    //  2. Then we can iterate through the array again to calculate F(k) for k = 1 to n-1 using the formula F(k) = F(k-1) + sum_arr - n * nums[n-k].
    //  3. We can keep track of the maximum value of F(k) and return it at the end.
    //  4. The formula F(k) = F(k-1) + sum_arr - n * nums[n-k] can be derived from the definition of F(k) and the fact that rotating the array by one position to the right is equivalent to moving the last element to the front of the array.
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        long long sum_arr = 0;
        for (int i = 0; i < n; i++)
            sum_arr += nums[i];
        long long tmp = 0;
        for (int i = 0; i < n; i++)
            tmp += i * nums[i];
        long long ans = tmp;
        for (int i = 0; i < n; i++)
        {
            tmp = tmp - sum_arr + nums[i] * n;
            if (tmp > ans)
                ans = tmp;
        }
        return int(ans);
    }
};