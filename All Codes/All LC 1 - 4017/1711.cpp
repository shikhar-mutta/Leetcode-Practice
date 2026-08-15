// Link: https://leetcode.com/problems/count-good-meals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) where n is the length of the input array.
// SC: O(1) for storing the total count of good meals.
// Approach:
//   1. Sort the input array.
//   2. For each power of 2, use two pointers to find pairs that sum to that power.
//   3. Count the number of valid pairs and add to the total.
//   4. Return the total modulo 10^9 + 7.
class Solution
{
public:
    int countPairs(vector<int> &a)
    {
        const int N = 1e9 + 7;
        sort(a.begin(), a.end());
        int t = 0;
        for (int m = 1, n = a.size(), p = a[n - 1] << 1; m <= p; m <<= 1)
            for (int j = 0, k = n - 1; j < k;)
            {
                int l = a[j] + a[k];
                if (l == m)
                    if (a[j] != a[k])
                    {
                        int u = j + 1, v = k - 1;
                        for (; u < k && a[u] == a[j]; ++u)
                            ;
                        for (; j < v && a[v] == a[k]; --v)
                            ;
                        t = (t + 1LL * (u - j) * (k - v)) % N, j = u, k = v;
                    }
                    else
                    {
                        t = (t + 1LL * (k - j) * (k - j + 1) / 2) % N;
                        break;
                    }
                else
                    l < m ? ++j : --k;
            }
        return t;
    }
};
