// Link: https://leetcode.com/problems/total-cost-to-hire-k-workers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> left, right;
        int i = 0, j = n - 1;
        for (int c = 0; c < candidates && i <= j; c++) left.push(costs[i++]);
        for (int c = 0; c < candidates && i <= j; c++) right.push(costs[j--]);

        long long total = 0;
        for (int hired = 0; hired < k; hired++) {
            int pick;
            if (!left.empty() && (right.empty() || left.top() <= right.top())) {
                pick = left.top(); left.pop();
                if (i <= j) left.push(costs[i++]);
            } else {
                pick = right.top(); right.pop();
                if (i <= j) right.push(costs[j--]);
            }
            total += pick;
        }
        return total;
    }
};
