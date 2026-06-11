// Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N log M). SC: O(1).
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int result, ans, low = 1, high = *max_element(nums.begin(), nums.end());
        // BS on devisor
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int sum = 0;
            for (int i : nums)
            {
                sum += (i + mid - 1) / mid; // ceil(i/mid)
                if (sum > threshold)        // Early Stopping if sum already exceeds threshold
                    break;
            }
            if (sum > threshold)
                low = mid + 1;
            else
                ans = mid, high = mid - 1;
        }
        return ans;
    }
};
