// Link: https://leetcode.com/problems/put-marbles-in-bags/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(NlogN), SC: O(N)
//  Approach: We can use a greedy approach to solve this problem. We can calculate the sum of the weights of each pair of adjacent bags and store them in a vector. Then, we can sort the vector and take the sum of the largest k-1 pairs and the sum of the smallest k-1 pairs. The difference between these two sums will be the maximum difference we can achieve by putting the marbles in the bags.
class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        if (k == 1)
            return 0;

        vector<long long> pairs;
        for (int i = 1; i < weights.size(); i++)
        {
            pairs.push_back(weights[i - 1] + weights[i]);
        }

        long long min_val = 0, max_val = 0;

        nth_element(pairs.begin(), pairs.begin() + k - 1, pairs.end());
        for (int i = 0; i < k - 1; i++)
        {
            min_val += pairs[i];
        }

        nth_element(pairs.begin(), pairs.begin() + k - 1, pairs.end(),
                    greater<>());
        for (int i = 0; i < k - 1; i++)
        {
            max_val += pairs[i];
        }

        return max_val - min_val;
    }
};