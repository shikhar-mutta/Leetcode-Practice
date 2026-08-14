// Link: https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end());
        double total = 0;
        for (int x : nums) total += x;
        double target = total / 2.0;
        double reduced = 0;
        int ops = 0;
        while (reduced < target) {
            double top = pq.top(); pq.pop();
            reduced += top / 2.0;
            pq.push(top / 2.0);
            ops++;
        }
        return ops;
    }
};
