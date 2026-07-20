// Link: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * log(n)) where n is the size of nums.
    // SC: O(n) where n is the size of nums.
    // Approach:
    // 1. We will create a vector mx of size 100 to store the maximum number for each digit sum.
    // 2. We will iterate through the nums array and for each number, we will calculate its digit sum using the digitSum function.
    // 3. If there is already a number with the same digit sum in mx, we will update the answer with the sum of the current number and the maximum number with the same digit sum.
    // 4. We will update the maximum number for the current digit sum in mx.
    // 5. Finally, we will return the answer.
    int digitSum(int x)
    {
        int sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int> &nums)
    {
        vector<int> mx(100, -1);
        int ans = -1;
        for (int x : nums)
        {
            int s = digitSum(x);
            if (mx[s] != -1)
            {
                ans = max(ans, x + mx[s]);
            }
            mx[s] = max(mx[s], x);
        }
        return ans;
    }
};