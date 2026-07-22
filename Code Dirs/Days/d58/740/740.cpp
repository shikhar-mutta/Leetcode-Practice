// Link: https://leetcode.com/problems/delete-and-earn/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the number of elements in the input array and m is the maximum value in the array.
    // SC: O(m) where m is the maximum value in the input array.
    // Approach:
    // 1. We first find the maximum value in the input array to determine the size of the points array.
    // 2. We create a points array where each index represents a number from 0 to the maximum value in the input array. The value at each index represents the total points we can earn by taking that number (i.e., the number multiplied by its frequency in the input array).
    // 3. We then use a dynamic programming approach similar to the "House Robber" problem. We maintain two variables, prev1 and prev2, to keep track of the maximum points we can earn up to the previous two indices.
    // 4. For each index i in the points array, we calculate the maximum points we can earn by either taking the current number (which means we cannot take the previous number) or skipping it (which means we can take the previous number). We update prev1 and prev2 accordingly.
    // 5. Finally, we return prev1, which contains the maximum points we can earn by considering all numbers in the input array.
    // 6. This approach ensures that we efficiently calculate the maximum points while adhering to the constraints of the problem, where taking a number removes its adjacent numbers from consideration.
    int deleteAndEarn(vector<int> &nums)
    {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<long long> points(maxVal + 1, 0);
        for (int x : nums)
            points[x] += x;

        long long prev2 = 0, prev1 = 0;
        for (int i = 0; i <= maxVal; i++)
        {
            long long cur = max(prev1, prev2 + points[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
