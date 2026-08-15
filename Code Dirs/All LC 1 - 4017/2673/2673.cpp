// Link: https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        long long ans = 0;
        for (int i = n / 2; i >= 1; i--) {
            int left = cost[2*i - 1], right = cost[2*i + 1 - 1];
            ans += abs(left - right);
            cost[i-1] += max(left, right);
        }
        return (int)ans;
    }
};
