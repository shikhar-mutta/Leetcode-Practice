// Link: https://leetcode.com/problems/number-of-recent-calls/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the number of calls to ping.
// SC: O(n), where n is the number of calls to ping.
// Approach:
// 1. We will use a queue to store the calls to ping.
// 2. We will push the current call to ping into the queue.
// 3. We will then pop all the calls that are older than 3000 milliseconds from the queue.
// 4. We will return the size of the queue, which is the number of calls to ping that are within the last 3000 milliseconds.
// 5. We will use a queue to store the calls to ping.

class RecentCounter
{
public:
    queue<int> q;

    RecentCounter() {}

    int ping(int t)
    {
        q.push(t);

        while (!q.empty() && q.front() < t - 3000)
        {
            q.pop();
        }

        return q.size();
    }
};
