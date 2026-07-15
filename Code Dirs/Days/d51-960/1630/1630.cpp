// Link: https://leetcode.com/problems/arithmetic-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) where n is the number of queries and m is the length of the subarray
// SC: O(m) where m is the length of the subarray
// Approach:
// 1. For each query, find the minimum and maximum elements in the subarray defined by l[i] and r[i].
// 2. Calculate the common difference d of the arithmetic sequence using the formula: d = (max - min) / (len - 1), where len is the length of the subarray
// 3. If the maximum and minimum elements are equal, then the subarray is an arithmetic sequence, so we add true to the result vector.
// 4. If the difference between the maximum and  minimum elements is not divisible by (len - 1), then the subarray cannot be an arithmetic sequence, so we add false to the result vector.
// 5. Otherwise, we create a boolean vector n of size len to keep track of the elements in the subarray. We iterate through the subarray and check if each element can be placed in the arithmetic sequence defined by the minimum element and the common difference d. If any element cannot be placed in the sequence or if there is a duplicate element, we break the loop and add false to
class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> res;
        for (auto i = 0, j = 0; i < l.size(); ++i)
        {
            auto [p_min, p_max] = minmax_element(begin(nums) + l[i], begin(nums) + r[i] + 1);
            int len = r[i] - l[i] + 1, d = (*p_max - *p_min) / (len - 1);
            if (*p_max == *p_min)
                res.push_back(true);
            else if ((*p_max - *p_min) % (len - 1))
                res.push_back(false);
            else
            {
                vector<bool> n(len);
                for (j = l[i]; j <= r[i]; ++j)
                {
                    if ((nums[j] - *p_min) % d || n[(nums[j] - *p_min) / d])
                        break;
                    n[(nums[j] - *p_min) / d] = true;
                }
                res.push_back(j > r[i]);
            }
        }
        return res;
    }
};