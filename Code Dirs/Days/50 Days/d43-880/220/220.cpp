// Link: https://leetcode.com/problems/contains-duplicate-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogk), SC: O(k)
    // Approach: We use a sliding window of size indexDiff to keep track of the last indexDiff elements. We use a set to maintain the values in the window, which allows us to efficiently check for the presence of a value within valueDiff of the current element. For each element, we check if there exists a number in the set that is within valueDiff of the current number. If such a number exists, we return true. Otherwise, we add the current number to the set and remove the oldest number if the window size exceeds indexDiff.
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        set<long long> window; // values of the last indexDiff elements
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (i > indexDiff)
                window.erase(nums[i - indexDiff - 1]);
            // smallest value >= nums[i] - valueDiff; close enough iff <= nums[i] + valueDiff
            auto it = window.lower_bound((long long)nums[i] - valueDiff);
            if (it != window.end() && *it <= (long long)nums[i] + valueDiff)
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
