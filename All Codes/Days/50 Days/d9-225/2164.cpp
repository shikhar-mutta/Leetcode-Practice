// Link: https://leetcode.com/problems/sort-even-and-odd-indices-independently/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Use 2 vec to store even & odd. TC: O(nlogn) SC: O(n)
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        vector<int> even, odd;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        // sort even in ascending & odd in descending order
        sort(even.begin(), even.end());
        sort(odd.rbegin(), odd.rend());
        // sort(odd.begin(), odd.end(), greater<int>());
        // merge even & odd vec to get the final result
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                nums[i] = even[i / 2];
            else
                nums[i] = odd[i / 2];
        }
        return nums;
    }
};
