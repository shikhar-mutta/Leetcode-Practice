// Link: https://leetcode.com/problems/minimize-deviation-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> maxHeap;
        int minVal = INT_MAX;
        for (int x : nums) {
            if (x % 2 == 1) x *= 2;
            maxHeap.push(x);
            minVal = min(minVal, x);
        }
        int best = INT_MAX;
        while (true) {
            int top = maxHeap.top(); maxHeap.pop();
            best = min(best, top - minVal);
            if (top % 2 == 1) break;
            top /= 2;
            minVal = min(minVal, top);
            maxHeap.push(top);
        }
        return best;
    }
};
