// Link: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: sort workers by wage/quality ratio ascending. For each
// worker as the "rate-setting" one (paying everyone at their ratio),
// maintain a max-heap of qualities among the k cheapest-quality workers
// seen so far (by ratio order); once k workers are available, the cost
// at this ratio is ratio * sumOfQualities, track the minimum. Evict the
// highest-quality worker from the heap when exceeding k to keep the sum minimal.
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return (double)wage[a] / quality[a] < (double)wage[b] / quality[b];
        });

        priority_queue<int> maxHeap;
        long long qualitySum = 0;
        double best = DBL_MAX;
        for (int i : idx) {
            maxHeap.push(quality[i]);
            qualitySum += quality[i];
            if ((int)maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }
            if ((int)maxHeap.size() == k) {
                double ratio = (double)wage[i] / quality[i];
                best = min(best, ratio * qualitySum);
            }
        }
        return best;
    }
};
