// Link: https://leetcode.com/problems/sorted-gcd-pair-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n + q log n), SC: O(n)
//  Approach: We can use a frequency array to count the occurrences of each number in the input array. Then, we can iterate through the frequency array in reverse order and calculate the number of pairs that have a GCD equal to the current number. We can use the formula n * (n - 1) / 2 to calculate the number of pairs for each number. We can also use a prefix sum array to store the cumulative number of pairs for each number. Finally, we can use binary search to find the number of pairs that have a GCD less than or equal to each query value.
class Solution
{
    using ll = long long;

public:
    vector<int> gcdValues(vector<int> &A, vector<long long> &queries)
    {
        int mx = ranges::max(A);
        vector<int> freq(mx + 1, 0);
        vector<ll> GCD(mx + 1, 0);

        for (auto &a : A)
            freq[a]++;

        for (int i = mx; i > 0; i--)
        {
            ll sm = 0, extra = 0;
            for (int j = i; j <= mx; j += i)
                sm += freq[j], extra += GCD[j];
            GCD[i] = sm * (sm - 1) / 2 - extra;
        }

        partial_sum(GCD.begin(), GCD.end(), GCD.begin());

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
            res[i] = ranges::upper_bound(GCD, queries[i]) - GCD.begin();

        return res;
    }
};
