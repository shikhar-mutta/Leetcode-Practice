// Link: https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + candiesCount[i];

        vector<bool> res;
        for (auto& q : queries) {
            int type = q[0];
            long long dayPlus1 = (long long)q[1] + 1;
            long long cap = q[2];
            long long minEaten = dayPlus1;
            long long maxEaten = dayPlus1 * cap;
            long long lo = prefix[type] + 1;
            long long hi = prefix[type+1];
            res.push_back(!(maxEaten < lo || minEaten > hi));
        }
        return res;
    }
};
