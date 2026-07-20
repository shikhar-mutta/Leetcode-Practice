// Link: https://leetcode.com/problems/zero-array-transformation-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n) where n is the length of the string
    // SC: O(n) for the hash vectors
    //  Approach:
    //   1. We can divide the strings s and t into k substrings of equal length
    //   2. We can then sort the substrings of s and t and compare them
    //   3. If they are equal, then we can rearrange the substrings of s to form t
    //   4. If they are not equal, then we cannot rearrange the substrings of s to form t
    //   5. Finally, we return true if we can rearrange the substrings of s to form t, otherwise we return false
    //  We can use a priority queue to keep track of the maximum end of the queries that are currently active
    static int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        const int n = nums.size(), qz = queries.size();
        vector<vector<int>> qEnd(n);
        for (int i = 0; i < qz; i++)
            qEnd[queries[i][0]].push_back(queries[i][1]);

        priority_queue<int> pq; // max heap for ends of queries
        // number of overlapping queries ending at i in line sweeping
        vector<int> cntQ(n + 1, 0);
        int dec = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            const int x = nums[i];
            dec += cntQ[i]; // current max possible number for decrementing
            for (int j : qEnd[i])
                pq.push(j); // push ends of queries starting at i
            int k;
            for (; x > dec && pq.size() > 0 && (k = pq.top()) >= i; dec++)
            {
                cntQ[k + 1]--;
                pq.pop();
            }
            if (x > dec)
                return -1;
        }
        return pq.size();
    }
};