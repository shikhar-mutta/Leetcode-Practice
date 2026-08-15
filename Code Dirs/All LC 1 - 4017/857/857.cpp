// Link: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return (double)wage[a] / quality[a] < (double)wage[b] / quality[b];
        });

        priority_queue<int> maxHeap;
        long long qSum = 0;
        double best = DBL_MAX;
        for (int i : idx) {
            maxHeap.push(quality[i]);
            qSum += quality[i];
            if ((int)maxHeap.size() > k) {
                qSum -= maxHeap.top();
                maxHeap.pop();
            }
            if ((int)maxHeap.size() == k) {
                double ratio = (double)wage[i] / quality[i];
                best = min(best, ratio * qSum);
            }
        }
        return best;
    }
};
