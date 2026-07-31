// Link: https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 log n) SC: O(n)
// Approach: We can use a bit manipulation approach to solve this problem. We can iterate through all the possible pairs of elements in the array and calculate their bitwise AND. We can then check if the result is equal to zero. If it is, we can increment the count of valid triplets. We can also use a hash map to store the frequency of each element in the array to avoid counting duplicate triplets.
class Solution
{
public:
    int countTriplets(vector<int> &a)
    {
        int n = a.size(), ans = 0, c[1 << 16];
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++)
            for (int j = a[i]; j > 0; j = (j - 1) & a[i])
                c[j]++;
        for (int i = 1; i < (1 << 16); i++)
            if (__builtin_popcount(i) & 1)
                ans += c[i] * c[i] * c[i];
            else
                ans -= c[i] * c[i] * c[i];
        ans = n * n * n - ans;
        return ans;
    }
};