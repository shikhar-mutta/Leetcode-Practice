// Link: https://leetcode.com/problems/minimize-deviation-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX;
        for (int x : nums) {
            if (x % 2 == 1) x *= 2;
            pq.push(x);
            mn = min(mn, x);
        }
        int ans = pq.top() - mn;
        while (pq.top() % 2 == 0) {
            int top = pq.top(); pq.pop();
            top /= 2;
            mn = min(mn, top);
            pq.push(top);
            ans = min(ans, pq.top() - mn);
        }
        return ans;
    }
};
