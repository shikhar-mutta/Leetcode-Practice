// Link: https://leetcode.com/problems/total-score-of-dungeon-runs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n), SC: O(n)
    long long totalScore(int hp, vector<int> &damage, vector<int> &requirement)
    {
        int n = damage.size();

        // prefix[k] = total damage of rooms [0 .. k-1]. Strictly increasing
        // because every damage[i] >= 1, which is what lets us binary search.
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + damage[i];

        long long result = 0;
        for (int i = 0; i < n; i++)
        {
            // A run starting at j (j <= i) reaches room i with health
            //   hp - (prefix[i+1] - prefix[j]).
            // Room i scores  <=>  prefix[j] >= prefix[i+1] + requirement[i] - hp.
            long long threshold = prefix[i + 1] + requirement[i] - hp;

            // Smallest j with prefix[j] >= threshold; all j..i then qualify.
            int j = lower_bound(prefix.begin(), prefix.end(), threshold) - prefix.begin();
            if (j <= i)
                result += i - j + 1; // valid starts are j, j+1, ..., i
        }
        return result;
    }
};
