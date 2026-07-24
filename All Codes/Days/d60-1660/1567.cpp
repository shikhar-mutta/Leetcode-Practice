// Link: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n)
    //  Approach:
    //  1. We will iterate through the array and keep track of the start and end indices of the subarrays that do not contain 0.
    //  2. For each subarray, we will count the number of negative numbers. If the count is even, we can take the entire subarray. If the count is odd, we will remove the first or last negative number
    //  3. We will keep track of the maximum length of the subarray with positive product and return it at the end.
    //  4. If the array contains only 0's, we will return 0.
    int getMaxLen(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> parts;
        int zeroCnt = 0;
        int start = -1;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                zeroCnt++;
            if (nums[i] == 0 && start < end && start != -1)
            {
                parts.push_back({start, end});
                start = -1;
            }
            else if (nums[i] == 0)
            {
                start = -1;
            }
            if (start == -1 && nums[i] != 0)
                start = i;
            end = i;
        }
        if (start != -1 && start < end)
        {
            parts.push_back({start, end});
        }
        if (parts.size() == 0 && zeroCnt == 0)
        {
            parts.push_back({0, n - 1});
        }
        int maxLen = 0;

        for (auto [left, right] : parts)
        {
            int negCnt = 0;
            for (int i = left; i <= right; i++)
            {
                if (nums[i] < 0)
                    negCnt++;
            }

            if (negCnt % 2 == 0)
            {
                maxLen = max(maxLen, right - left + 1);
            }
            else
            {

                int leftPart = 0;
                for (int i = left; i <= right; i++)
                {
                    leftPart++;
                    if (nums[i] < 0)
                        break;
                }

                int rightPart = 0;
                for (int j = right; j >= left; j--)
                {
                    rightPart++;
                    if (nums[j] < 0)
                        break;
                }

                int minPart = min(leftPart, rightPart);

                maxLen = max(maxLen, right - left + 1 - minPart);
            }
        }
        return maxLen;
    }
};