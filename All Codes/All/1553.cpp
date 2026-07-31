// Link: https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n)) SC: O(log(n))
// Approach: We can use a recursive function to calculate the minimum number of days to eat n oranges. We can use memoization to store the results of previously calculated values to avoid redundant calculations. The base case is when n is less than or equal to 1, in which case we return n. For other values of n, we can calculate the minimum number of days by considering two options: either we eat one orange and call the function recursively with n-1, or we divide n by 2 or 3 and call the function recursively with the result. We take the minimum of these two options and add 1 to account for the current day. Finally, we return the result.
using ll = long long;
unordered_map<ll, ll> m;
class Solution
{
public:
    ll f(int n)
    {
        if (n <= 1)
            return n;
        if (m.find(n) != m.end())
            return m[n];
        return m[n] = 1 + min(n % 2 + f(n / 2), n % 3 + f(n / 3));
    }
    int minDays(int n)
    {
        return f(n);
    }
};
