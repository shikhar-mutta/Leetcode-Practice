// Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int mn = *max_element(nums.begin(), nums.end()), mx = *min_element(nums.begin(), nums.end());

        return __gcd(mn, mx);
    }
};
