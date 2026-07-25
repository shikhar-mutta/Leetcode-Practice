// Link: https://leetcode.com/problems/minimize-maximum-of-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the size of the input array nums.
// SC: O(1), as we are using a constant amount of extra space for variables
//  Approach:
//   1. We initialize two variables sum and res to 0. The variable sum will be used to keep track of the cumulative sum of the elements in the input array nums, and res will be used to keep track of the maximum value of the average of the elements in the input array nums.
//   2. We iterate through each element of the input array nums using a for loop. For each element, we add its value to the variable sum.
//   3. We calculate the average of the elements in the input array nums up to the current index i using the formula (sum + i) / (i + 1). This formula calculates the ceiling of the average by adding i to the sum before dividing by (i + 1).
//   4. We update the variable res to be the maximum of its current value and the calculated average.
//  5. Finally, we return the value of res, which represents the minimum possible maximum value of the elements in the input array nums after performing the allowed operations.
class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        long long sum = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            long long avg = (sum + i) / (i + 1); // ceil(sum / (i+1))
            res = max(res, avg);
        }
        return res;
    }
};