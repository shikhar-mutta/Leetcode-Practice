// Link: https://leetcode.com/problems/maximum-equal-frequency/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: Count frequency of each number and frequency of frequencies,
//  check if all numbers have the same frequency or if we can remove one number to make
//  all numbers have the same frequency, return the maximum length of prefix that satisfies this.
//  Note: The solution uses two arrays t and f to keep track of the frequency of each number and the frequency of frequencies respectively.
class Solution
{
public:
    int maxEqualFreq(vector<int> &nums)
    {
        int t[100001] = {0}, f[100001] = {0}, ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int cF = ++t[nums[i]];
            f[cF]++;
            int total = cF * f[cF];
            if (total == i + 1 && i + 1 < n)
                ans = i + 2;
            else if (total == i)
                ans = i + 1;
        }
        return ans;
    }
};