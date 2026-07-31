// Link: https://leetcode.com/problems/restore-finishing-order/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> f(friends.begin(), friends.end());
        vector<int> result;
        for (int x : order) if (f.count(x)) result.push_back(x);
        return result;
    }
};
