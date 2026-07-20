// Link: https://leetcode.com/problems/sort-the-jumbled-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n) where n is the number of elements in nums
    // SC: O(n) where n is the number of elements in nums
    // Approach:
    // 1. Create a vector of pairs to store the mapped number and its original index.
    // 2. For each number in nums, calculate its mapped value using the mapping array.
    // 3. Sort the vector of pairs based on the mapped values.
    // 4. Create a result vector and populate it with the original numbers in the order of their mapped values.
    // 5. Return the result vector.
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<pair<int, int>> pairs;

        for (int i = 0; i < nums.size(); i++)
        {
            int mapped_n = 0, base = 1;
            int num = nums[i];

            if (num == 0)
            {
                mapped_n = mapping[0];
            }
            else
            {
                while (num > 0)
                {
                    int digit = num % 10;
                    num /= 10;
                    mapped_n += base * mapping[digit];
                    base *= 10;
                }
            }

            pairs.push_back({mapped_n, i});
        }

        sort(pairs.begin(), pairs.end());

        vector<int> res;
        for (auto &p : pairs)
        {
            res.push_back(nums[p.second]);
        }

        return res;
    }
};