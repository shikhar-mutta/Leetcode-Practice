// Link: https://leetcode.com/problems/queue-reconstruction-by-height/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn), SC: O(n).
    // Approach: We first sort the people in descending order of height. If two people have the same height, we sort them in ascending order of their k value. Then, we iterate through the sorted list and insert each person into the result vector at the index equal to their k value. This ensures that each person's "taller-or-equal ahead of me" count is maintained correctly.
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        // tallest first (k ascending among equals); inserting at index k
        // keeps each person's "taller-or-equal ahead of me" count exact,
        // and later (shorter) insertions never break it
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1]; });

        vector<vector<int>> res;
        res.reserve(people.size());
        for (auto &p : people)
            res.insert(res.begin() + p[1], p);
        return res;
    }
};
