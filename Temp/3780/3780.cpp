// Link: https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    //  SC: O(1)
    // Approach:
    //  1. We can divide the numbers into three groups based on their remainder when divided by 3:
    //     - Group 0: Numbers that are divisible by 3 (remainder 0)
    //     - Group 1: Numbers that leave a remainder of 1 when divided by 3
    //     - Group 2: Numbers that leave a remainder of 2 when divided by 3
    //  2. We can keep track of the three largest numbers in each group.
    //  3. To find the maximum sum of three numbers that is divisible by 3
    //     we can consider the following combinations:
    //     - Three numbers from Group 0
    //     - Three numbers from Group 1
    //     - Three numbers from Group 2
    //     - One number from each group (0, 1, 2)
    //  4. We can calculate the sum for each combination and return the maximum sum that is divisible by 3.
    //  5. If there are not enough numbers in any group to form a valid combination, we can ignore that combination.
    //  6. Finally, we return the maximum sum that is divisible by 3.
    int maximumSum(vector<int> &nums)
    {
        int n = nums.size();
        int mx01 = INT_MIN, mx02 = INT_MIN, mx03 = INT_MIN;
        int mx11 = INT_MIN, mx12 = INT_MIN, mx13 = INT_MIN;
        int mx21 = INT_MIN, mx22 = INT_MIN, mx23 = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] % 3 == 0)
            {
                if (nums[i] > mx01)
                    mx03 = mx02, mx02 = mx01, mx01 = nums[i];
                else if (nums[i] > mx02)
                    mx03 = mx02, mx02 = nums[i];
                else if (nums[i] > mx03)
                    mx03 = nums[i];
            }
            else if (nums[i] % 3 == 1)
            {
                if (nums[i] > mx11)
                    mx13 = mx12, mx12 = mx11, mx11 = nums[i];
                else if (nums[i] > mx12)
                    mx13 = mx12, mx12 = nums[i];
                else if (nums[i] > mx13)
                    mx13 = nums[i];
            }
            else
            {
                if (nums[i] > mx21)
                    mx23 = mx22, mx22 = mx21, mx21 = nums[i];
                else if (nums[i] > mx22)
                    mx23 = mx22, mx22 = nums[i];
                else if (nums[i] > mx23)
                    mx23 = nums[i];
            }
        }
        int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        if (mx03 != INT_MIN)
            s1 = mx01 + mx02 + mx03;
        if (mx13 != INT_MIN)
            s2 = mx11 + mx12 + mx13;
        if (mx23 != INT_MIN)
            s3 = mx21 + mx22 + mx23;
        if (mx01 != INT_MIN && mx11 != INT_MIN && mx21 != INT_MIN)
            s4 = mx01 + mx11 + mx21;
        return max({s1, s2, s3, s4});
    }
};