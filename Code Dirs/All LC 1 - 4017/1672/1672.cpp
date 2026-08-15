// Link: https://leetcode.com/problems/richest-customer-wealth/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int best = 0;
        for (auto& acc : accounts) {
            int sum = 0;
            for (int x : acc) sum += x;
            best = max(best, sum);
        }
        return best;
    }
};
