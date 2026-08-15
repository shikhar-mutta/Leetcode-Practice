// Link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //   Approach:
    //   1. For each ant moving to the left, the time it takes to fall off the plank is equal to its position on the plank (since it moves at a speed of 1 unit per second).
    //   2. For each ant moving to the right, the time it takes to fall off the plank is equal to the distance from its position to the right end of the plank, which is (n - position).
    //   3. The last moment before all ants fall off the plank is the maximum time taken by any ant to fall off, which can be calculated by taking the maximum of the times for all ants moving to the left and all ants moving to the right.
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int res = 0;
        for (int p : left)
            res = max(res, p);
        for (int p : right)
            res = max(res, n - p);
        return res;
    }
};