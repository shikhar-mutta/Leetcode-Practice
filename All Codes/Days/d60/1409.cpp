// Link: https://leetcode.com/problems/queries-on-a-permutation-with-key/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m) where n is the length of the queries array and m is the length of the permutation array.
    // SC: O(m) where m is the length of the permutation array.
    // Approach:
    //   1. We will maintain a permutation array of size m initialized with values from 1 to m.
    //   2. For each query, we will find the index of the query in the permutation array and store it in the result array.
    //   3. We will then move the queried element to the front of the permutation array.
    //   4. We will return the result array after processing all the queries.
    vector<int> processQueries(vector<int> &queries, int m)
    {
        vector<int> res, p;
        int n = queries.size(), pos;
        for (int i = 1; i <= m; i++)
            p.push_back(i);
        for (int i = 0; i < n; i++)
        {
            pos = find(p.begin(), p.end(), queries[i]) - p.begin();
            res.push_back(pos);
            p.erase(p.begin() + pos);
            p.insert(p.begin(), queries[i]);
        }
        return res;
    }
};