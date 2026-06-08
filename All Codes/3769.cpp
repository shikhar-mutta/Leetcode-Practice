// Link: https://leetcode.com/problems/sort-integers-by-binary-reflection/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n), SC: O(n)
    vector<int> sortByReflection(vector<int> &nums)
    {
        auto binReflect = [](int n)
        {
            int res = 0;
            while (n > 0)
            {
                res <<= 1;
                res |= (n & 1);
                n >>= 1;
            }
            return res;
        };
        vector<pair<int, int>> pairs;
        sort(nums.begin(), nums.end());
        for (int num : nums)
        {
            pairs.push_back({binReflect(num), num});
        }
        sort(pairs.begin(), pairs.end());
        vector<int> result;
        for (const auto &pair : pairs)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
