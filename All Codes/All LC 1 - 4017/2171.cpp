// Link: https://leetcode.com/problems/removing-minimum-number-of-magic-beans/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the number of elements in d and m is the maximum value in d.
    // SC: O(m) where m is the maximum value in d.
    // Approach:
    //   1. We will calculate the cost to remove all beans from the bags.
    //   2. We will calculate the cost to remove all beans from the bags with less than i beans.
    //   3. We will calculate the cost to remove all beans from the bags with more than i beans.
    //   4. We will return the minimum cost to remove all beans from the bags.
    //   5. We will iterate through all the possible values of i and calculate the cost to remove all beans from the bags with less than i beans and the cost to remove all beans from the bags with more than i beans.
    //   6. We will return the minimum cost to remove all beans from the bags.
    long long minimumRemoval(vector<int> &d)
    {
        int64_t upper_cost = 0;
        int64_t lower_cost = 0;
        int64_t lower_count = 0;
        int64_t f[100001]{};
        int i_max = 0;
        for (int x : d)
        {
            i_max = max(i_max, x);
            upper_cost += x;
            ++f[x];
        }
        int n = d.size();
        int64_t res = LLONG_MAX;
        //        cout << "cost to zero: " << upper_cost << endl;
        for (int i = 1; i <= i_max; ++i)
        {
            //            cout << "====== i: " << i << endl;
            lower_cost += f[i - 1] * (i - 1);
            //            cout << "lower_cost: " << lower_cost << endl;
            upper_cost -= n;
            //            cout << "upper_cost: " << upper_cost << endl;
            n -= f[i];
            //            cout << "n: " << n << endl;
            res = min(res, upper_cost + lower_cost);
        }
        return res;
    }
};