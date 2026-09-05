// Link: https://leetcode.com/problems/count-integers-appearing-in-a-single-block/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSpecialIntegers(vector<int> &nums)
    {
        unordered_map<int, int> runs;
        // Count the number of runs for each integer in nums
        for (int i = 0; i < (int)nums.size(); i++)
            if (i == 0 || nums[i] != nums[i - 1])
                runs[nums[i]]++;
        // Count the number of integers that appear in a single block
        int ans = 0;
        for (auto &[x, r] : runs)
            if (r == 1)
                ans++;
        return ans;
    }
};