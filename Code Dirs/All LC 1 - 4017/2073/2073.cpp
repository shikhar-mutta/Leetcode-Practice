// Link: https://leetcode.com/problems/time-needed-to-buy-tickets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;
        for (int i = 0; i < n; i++) {
            if (i <= k) time += min(tickets[i], tickets[k]);
            else time += min(tickets[i], tickets[k] - 1);
        }
        return time;
    }
};
