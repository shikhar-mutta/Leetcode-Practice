// Link: https://leetcode.com/problems/points-that-intersect-with-cars/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: counting.
    // TC: O(N * M), SC: O(1).
    int numberOfPoints(vector<vector<int>> &nums)
    {
        vector<int> count(101, 0);
        for (auto &num : nums)
            for (int i = num[0]; i <= num[1]; i++)
                count[i]++;

        int ans = 0;
        for (int i = 0; i <= 100; i++)
            if (count[i] > 0)
                ans++;
        return ans;
    }

    // Approach 2: bitset.
    // TC: O(N * M / 64), SC: O(1).
    int numberOfPoints2(vector<vector<int>> &nums)
    {
        bitset<101> count;
        for (auto &num : nums)
            for (int i = num[0]; i <= num[1]; i++)
                count.set(i);

        return count.count();
    }
};
