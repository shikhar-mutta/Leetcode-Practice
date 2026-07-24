// Link: https://leetcode.com/problems/minimum-jumps-to-reach-home/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the input array.
// SC: O(n) for storing the visited array.
// Approach:
//       1. Use a priority queue to store the current distance and the current position.
//       2. Use a visited array to mark the forbidden positions and the positions that have been visited.
//       3. Start from position 0 and push it into the priority queue with distance 0.
//       4. While the priority queue is not empty, pop the top element and check if the current position is equal to x. If it is, return the current distance.
//      5. If the current position is not equal to x, check if we can jump forward or backward. If we can jump forward, push the new position into the priority queue with distance +1. If we can jump backward, push the new position into the priority queue with distance +2 (since we need to jump forward again).
class Solution
{
    typedef pair<int, int> P;

public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, 0});
        vector<bool> vis(10000, false);
        for (int x : forbidden)
            vis[x] = true;
        if (vis[0])
            return -1;
        vis[0] = true;
        while (!q.empty())
        {
            auto [curDist, cur] = q.top();
            q.pop();
            if (cur == x)
                return curDist;
            if (cur - b > 0 && !vis[cur - b] && cur - b == x)
                return curDist + 1;
            // Jump forward.
            if (cur + a < 10000 && !vis[cur + a])
            {
                vis[cur + a] = true;
                q.push({curDist + 1, cur + a});
            }
            // Jump backward but jump forward again.
            if (cur - b > 0 && !vis[cur - b] && cur + a - b < 10000 &&
                !vis[cur + a - b])
            {
                vis[cur + a - b] = true;
                q.push({curDist + 2, cur + a - b});
            }
        }
        return -1;
    }
};
