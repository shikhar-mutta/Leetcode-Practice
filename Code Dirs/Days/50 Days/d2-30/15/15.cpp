// Link: https://leetcode.com/problems/3sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // Approach 2: Sorting + Two Pointers
        sort(nums.begin(), nums.end());
        int n = nums.size(), left, right, sum;
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0) break;
            if (i > 0 && (nums[i] == nums[i - 1]))
                continue;
            left = i + 1;
            right = n - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum > 0)
                    right--;
                else
                    left++;
            }
        }

        return ans;

        // Approach 1: Brute Force
        // set<vector<int>> ans;
        // int n = nums.size();
        // vector<int> arr = nums;
        // for (int i = 0; i < n; i++)
        // {
        //     set<int> hashset;
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         int third = -(arr[i] + arr[j]);
        //         if (hashset.find(third) != hashset.end())
        //         {
        //             vector<int> temp = {arr[i], arr[j], third};
        //             sort(temp.begin(), temp.end());
        //             ans.insert(temp);
        //         }
        //         hashset.insert(arr[j]);
        //     }
        // }
        // return vector<vector<int>>(ans.begin(), ans.end());
    }
};