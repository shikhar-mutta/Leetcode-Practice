// Link: https://leetcode.com/problems/open-the-lock/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10^4) where 10^4 is the total number of possible combinations (0000 to 9999).
// SC: O(10^4) where 10^4 is the total number of possible combinations (0000 to 9999).
// Approach: BFS
//  1. Use a queue to perform BFS starting from the initial combination "0000".
//  2. Use a set to keep track of deadends and visited combinations to avoid cycles
//  3. For each combination, generate all possible next combinations by turning each wheel one step forward or backward.
//  4. If the target combination is reached, return the number of steps taken.
//  5. If the queue is exhausted without reaching the target, return -1 indicating it's impossible to unlock.
//  6. The BFS ensures that the first time we reach the target, it is through the shortest path (minimum steps).
//  7. The modulo operation ensures that the wheel wraps around correctly (e.g., from '0' to '9' and vice versa).
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        string start = "0000";
        if (dead.count(start))
            return -1;
        if (start == target)
            return 0;

        queue<string> q;
        q.push(start);
        visited.insert(start);
        int steps = 0;

        while (!q.empty())
        {
            steps++;
            int sz = q.size();
            for (int k = 0; k < sz; k++)
            {
                string cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    for (int d = -1; d <= 1; d += 2)
                    {
                        string next = cur;
                        next[i] = '0' + (((next[i] - '0') + d + 10) % 10);
                        if (dead.count(next) || visited.count(next))
                            continue;
                        if (next == target)
                            return steps;
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};
