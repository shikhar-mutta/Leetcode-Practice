// Link: https://leetcode.com/problems/minimum-time-to-build-blocks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<int>> pq(blocks.begin(), blocks.end());
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            pq.push(b + split);
        }
        return pq.top();
    }
};
