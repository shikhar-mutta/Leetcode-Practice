// Link: https://leetcode.com/problems/find-missing-observations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//   Approach:
//   1. We can calculate the total sum of the rolls and the total sum of the rolls including the missing rolls.
//   2. We can calculate the sum of the missing rolls
//   3. We can check if the sum of the missing rolls is less than n or greater than 6 * n, if so return an empty vector
//   4. We can create a vector of size n and fill it with the average value of the missing rolls
//   5. We can calculate the remainder of the sum of the missing rolls and distribute it among the first few elements of the vector
//   6. We can return the vector of missing rolls
class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int sum = 0;
        for (int x : rolls)
        {
            sum += x;
        }
        int total = mean * (rolls.size() + n);
        int minus = total - sum;
        if (minus < n || minus > 6 * n)
        {
            return {};
        }
        vector<int> ans(n, minus / n);
        int rem = minus % n;
        for (int i = 0; i < rem; i++)
        {
            ans[i]++;
        }
        return ans;
    }
};