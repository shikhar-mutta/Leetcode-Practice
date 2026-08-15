// Link: https://leetcode.com/problems/first-element-with-unique-frequency/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: count each value's frequency, then count how many distinct
//  values share each frequency. Scan the array in order and return the
//  first element whose frequency is held by exactly one distinct value.
class Solution
{
public:
    int firstUniqueFreq(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> hash(maxi + 1, 0);
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]]++;
        }

        for (int i = 0; i <= maxi; i++)
        {
            cnt[hash[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (cnt[hash[nums[i]]] == 1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};