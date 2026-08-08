// Link: https://leetcode.com/problems/minimum-cost-to-connect-sticks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        int cost = 0;
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            cost += a + b;
            pq.push(a + b);
        }
        return cost;
    }
};
