// Link: https://leetcode.com/problems/summary-ranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        string st;
        int n = nums.size();
        for (int i = 0; i < n;)
        {
            int start = i, end;
            //  Find the end of the current range
            while (i + 1 < n && nums[i] + 1 == nums[i + 1])
                i++;
            //  If the start and end are the same, it's a single number; otherwise, it's a range
            if (start == i)
                ans.push_back(to_string(nums[start]));
            else //  Create the range string in the format "start->end"
                ans.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            i++;
        }
        return ans;
    }
};