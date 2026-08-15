// Link: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: For each node, we can either take its value as is or take its value XOR k. We want to maximize the sum of the values of the nodes. We can iterate through the nodes and for each node, we can check if taking its value XOR k is greater than taking its value as is. If it is, we take its value XOR k and add it to the sum. If it is not, we take its value as is and add it to the sum.
class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k,
                              vector<vector<int>> &edges)
    {
        long long sum = 0;
        int nk = INT_MAX;
        int pk = INT_MAX;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] ^ k) > nums[i])
            {
                count++;
                sum += nums[i] ^ k;
                pk = min(pk, (nums[i] ^ k) - nums[i]);
            }
            else
            {
                sum += nums[i];
                nk = min(nk, nums[i] - (nums[i] ^ k));
            }
        }
        if (count % 2 == 0)
            return sum;
        return max(sum - nk, sum - pk);
    }
};
