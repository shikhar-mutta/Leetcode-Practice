// Link: https://leetcode.com/problems/brick-wall/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m), SC: O(n*m)
    // Approach:
    //  1. For each row, we will calculate the prefix sum of the blocks and store it in a map with the count of how many times that prefix sum has occurred.
    //  2. The maximum count of any prefix sum will give us the maximum number of edges that can be crossed without hitting a brick.
    //  3. The answer will be the total number of rows minus the maximum count of any prefix sum.
    //  4. We will not consider the last block in each row as it does not contribute to any edge.
    //  5. Finally, we will return the result.
    int leastBricks(vector<vector<int>> &wall)
    {
        long long n = wall.size();
        unordered_map<long long, int> boundaryCnt;
        for (vector<int> &blocks : wall)
        {
            long long prev = 0;
            for (int i = 0; i < int(blocks.size()) - 1; i++)
            {
                prev += blocks[i];
                boundaryCnt[prev]++;
            }
        }

        int result = 0;
        for (auto [boundary, cnt] : boundaryCnt)
        {
            result = max(result, cnt);
        }

        return n - result;
    }
};