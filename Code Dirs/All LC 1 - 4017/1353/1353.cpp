// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = events.size();
        int i = 0, day = 0, count = 0;
        while (i < n || !minHeap.empty()) {
            if (minHeap.empty()) day = events[i][0];
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }
            while (!minHeap.empty() && minHeap.top() < day) minHeap.pop();
            if (!minHeap.empty()) {
                minHeap.pop();
                count++;
                day++;
            }
        }
        return count;
    }
};
