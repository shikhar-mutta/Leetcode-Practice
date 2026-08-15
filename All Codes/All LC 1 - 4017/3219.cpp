// Link: https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m)  SC: O(n + m)
//   Approach: For each cut, the cost is equal to the length of the cut multiplied by the number of pieces it will cut through. We can precompute the number of pieces for each cut using a prefix sum array. Then, we can iterate through the cuts and calculate the total cost.
class Solution
{
public:
    long long minimumCost(int m, int n, vector<int> &horizontalCut,
                          vector<int> &verticalCut)
    {
        vector<long long> cnt(1002);
        for (auto value : horizontalCut)
            cnt[value]++;
        for (int i = 1; i <= 1001; i++)
            cnt[i] += cnt[i - 1];
        long long answer = 0;
        for (auto value : verticalCut)
        {
            answer = answer + value * (1 + cnt[1000] - cnt[value]);
        }
        for (int i = 1; i <= 1001; i++)
            cnt[i] = 0;
        for (auto value : verticalCut)
            cnt[value]++;
        for (int i = 1; i <= 1001; i++)
            cnt[i] += cnt[i - 1];
        for (auto value : horizontalCut)
        {
            answer = answer + value * (1 + cnt[1000] - cnt[value - 1]);
        }
        return answer;
    }
};