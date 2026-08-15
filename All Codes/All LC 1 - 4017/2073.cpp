// Link: https://leetcode.com/problems/time-needed-to-buy-tickets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int time = 0, n = tickets.size();
        // use min to calculate the time needed for each person in the queue
        for (int i = 0; i < n; i++)
            time += (i <= k) ? min(tickets[i], tickets[k])
                             : min(tickets[i], tickets[k] - 1);
        return time;
    }
};
