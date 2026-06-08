// Link: https://leetcode.com/problems/find-missing-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) ~ O(nlogn). SC: O(n) for sorting + O(n) for missing vector ~ O(n).
    vector<int> findMissingElements(vector<int> &nums)
    {
        vector<int> missing;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] + 1 != nums[i])
                for (int j = nums[i - 1] + 1; j < nums[i]; j++)
                    missing.push_back(j);
        }
        return missing;
    }
};
