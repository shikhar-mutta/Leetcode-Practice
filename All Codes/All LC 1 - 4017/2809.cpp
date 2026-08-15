// Link: https://leetcode.com/problems/minimum-time-to-make-array-sum-at-most-x/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) where n is the length of the array, SC: O(n) where n is the length of the array
// Approach: We can use dynamic programming to find the minimum time required to make the sum of the array at most x. We will maintain a dp array where dp[i] represents the maximum sum we can achieve by using i operations. We will iterate through the elements of the array and for each element, we will update the dp array by considering the current element and the number of operations used. Finally, we will check for the minimum number of operations required to make the sum of the array at most x.
class Solution
{
public:
    int minimumTime(vector<int> &array1, vector<int> &array2, int x)
    {
        int n = array1.size();
        int sum1 = accumulate(array1.begin(), array1.end(), 0);
        int sum2 = accumulate(array2.begin(), array2.end(), 0);
        if (sum1 <= x)
        {
            return 0;
        }
        vector<pair<int, int>> array(n);
        for (int i = 0; i < n; i++)
        {
            array[i] = {array2[i], array1[i]};
        }
        ranges::sort(array);
        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++)
        {
            int number2 = array[i].first;
            int number1 = array[i].second;
            for (int j = i + 1; j >= 1; j--)
            {
                dp[j] = max(dp[j], dp[j - 1] + number1 + j * number2);
            }
        }
        for (int t = 0; t <= n; t++)
        {
            int currentSum = sum1 + t * sum2 - dp[t];
            if (currentSum <= x)
            {
                return t;
            }
        }
        return -1;
    }
};