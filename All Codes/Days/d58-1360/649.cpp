// Link: https://leetcode.com/problems/dota2-senate/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) SC: O(n)
    // Approach:
    // 1. We can use two queues to keep track of the indices of the senators from each party.
    // 2. We can iterate through the queues and compare the indices of the senators from each party.
    // 3. The senator with the smaller index will ban the senator from the other party
    // 4. The banned senator will be removed from the queue and the winning senator will be added back to the queue with an updated index (current index + n).
    // 5. We will continue this process until one of the queues is empty, indicating that all senators from that party have been banned.
    // 6. Finally, we will return the name of the party that has remaining senators in the queue.
    string predictPartyVictory(string senate)
    {
        queue<int> r, d;
        int n = senate.size();

        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }

        while (!r.empty() && !d.empty())
        {
            int ri = r.front();
            r.pop();
            int di = d.front();
            d.pop();

            if (ri < di)
                r.push(ri + n);
            else
                d.push(di + n);
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};