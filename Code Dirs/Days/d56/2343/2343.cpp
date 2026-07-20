// Link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * l + p) where n is the size of a, l is the length of each string in a, and p is the size of b.
    // SC: O(n * l) where n is the size of a, and l is the length of each string in a.
    // Approach:
    // 1. We will use counting sort to sort the strings in a based on their trimmed values.
    // 2. We will iterate through the strings in a and for each string, we will count the frequency of each digit in the trimmed value.
    // 3. We will then use the frequency array to determine the position of each string in the sorted order.
    // 4. We will store the sorted order of the strings in a 2D array r where r[d][i] represents the index of the i-th smallest trimmed value of length d.
    // 5. Finally, we will iterate through the queries in b and for each query, we will return the index of the k-th smallest trimmed value of length d from the sorted order stored in r .
    vector<int> smallestTrimmedNumbers(vector<string> &a, vector<vector<int>> &b)
    {
        int n = a.size(), l = a[0].size(), r[101][100], c[100], x[100], p = b.size();
        for (int i = 0; i < n; c[i] = i, ++i)
            ;
        for (int d = 1; d <= l; ++d)
        {
            int p = l - d, e[10] = {0}, s[10];
            for (int i = 0; i < n; ++e[a[c[i++]][p] - 48])
                ;
            s[0] = 0;
            for (int i = 1; i < 10; s[i] = s[i - 1] + e[i - 1], ++i)
                ;
            for (int i = 0; i < n; x[s[a[c[i]][p] - 48]++] = c[i], ++i)
                ;
            for (int i = 0; i < n; c[i] = r[d][i] = x[i], ++i)
                ;
        }
        vector<int> y(p);
        for (int i = 0; i < p; y[i] = r[b[i][1]][b[i][0] - 1], ++i)
            ;
        return y;
    }
};