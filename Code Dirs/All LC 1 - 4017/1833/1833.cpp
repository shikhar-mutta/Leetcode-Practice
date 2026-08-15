// Link: https://leetcode.com/problems/maximum-ice-cream-bars/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for (int c : costs) {
            if (coins < c) break;
            coins -= c;
            count++;
        }
        return count;
    }
};
