// Link: https://leetcode.com/problems/find-x-value-of-array-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k) SC: O(k)
//  Approach: iterate through the array and keep track of the count of each remainder when divided by k.
//  For each number in the array, calculate its remainder when divided by k and update the count of that remainder. Then, for each possible remainder, calculate the new remainder when multiplied by the current number and update the count accordingly. Finally, return the counts of each remainder as a vector.
class Solution
{
public:
    vector<long long> resultArray(vector<int> &nums, int k)
    {
        vector<long long> res(5, 0);
        long long prev[5]{};

        for (int num : nums)
        {
            long long curr[5]{};
            int idx1 = num % k;
            for (int r = 0; r < k; r++)
            {
                int idx2 = (idx1 * r) % k;
                curr[idx2] += prev[r];
                res[idx2] += prev[r];
            }
            curr[idx1]++;
            res[idx1]++;
            swap(prev, curr);
        }
        res.resize(k);
        return res;
    }
};