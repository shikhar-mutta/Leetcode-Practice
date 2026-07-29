// Link: https://leetcode.com/problems/kth-smallest-instructions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(h*v) SC: O(h*v)
// Approach: We can use combinatorial mathematics to determine the number of ways to arrange the moves. The total number of moves is h + v, and we need to choose h positions for horizontal moves (H) and v positions for vertical moves (V). The number of ways to arrange these moves is given by the binomial coefficient C(h + v, h) or C(h + v, v). We can precompute these values using dynamic programming. Then, we can construct the k-th smallest path by iteratively deciding whether to place an H or a V based on the number of remaining paths that can be formed with the remaining moves.
class Solution
{
public:
    string kthSmallestPath(vector<int> &destination, int k)
    {
        int v = destination[0], h = destination[1];
        vector<vector<long long>> C(h + v + 1, vector<long long>(h + v + 1, 0));
        for (int i = 0; i <= h + v; i++)
        {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++)
                C[i][j] = C[i - 1][j - 1] + (j <= i - 1 ? C[i - 1][j] : 0);
        }
        string res;
        int total = h + v;
        for (int i = 0; i < total; i++)
        {
            if (h == 0)
            {
                res += 'V';
                v--;
                continue;
            }
            if (v == 0)
            {
                res += 'H';
                h--;
                continue;
            }
            long long cnt = C[h - 1 + v][h - 1]; // ways if we place H here
            if (k <= cnt)
            {
                res += 'H';
                h--;
            }
            else
            {
                res += 'V';
                v--;
                k -= cnt;
            }
        }
        return res;
    }
};
