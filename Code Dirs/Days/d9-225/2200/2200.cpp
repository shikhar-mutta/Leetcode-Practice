// Link: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Using a variable to keep track of the last index. TC: O(n), SC: O(n)
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> ans;
        int last = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == key)
            {
                // We want to add all indices in the range [i - k, i + k] to the answer.
                int lo = max(last + 1, max(0, i - k));
                int hi = min((int)nums.size() - 1, i + k);
                for (int j = lo; j <= hi; j++)
                    ans.push_back(j);
                // track last ind.
                last = hi;
            }
        }
        return ans;
    }

    // // Approach 2: Using sorting and unique to remove duplicates. TC: O(n log n), SC: O(n)
    // vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    // {
    //     vector<int> ans;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (nums[i] == key)
    //         {
    //             // Add all indices from i-k to i+k to the answer vector
    //             for (int j = max(0, i - k); j <= min((int)nums.size() - 1, i + k); j++)
    //             {
    //                 ans.push_back(j);
    //             }
    //         }
    //     }
    //     // Remove duplicates and sort the answer vector
    //     sort(ans.begin(), ans.end());
    //     ans.erase(unique(ans.begin(), ans.end()), ans.end());
    //     return ans;
    // }
};
