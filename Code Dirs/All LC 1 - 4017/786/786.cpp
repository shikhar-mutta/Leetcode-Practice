// Link: https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((n+k) log n) SC: O(n)
// Approach: min-heap seeded with fraction arr[i]/arr[n-1] for each i<n-1 (smallest possible for that numerator index). Pop k-1 times, each time advancing that numerator's denominator index forward, pushing the next fraction with that same numerator.
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        using T = tuple<double,int,int>;
        priority_queue<T, vector<T>, greater<>> pq;
        for (int i = 0; i < n-1; i++) pq.push({(double)arr[i]/arr[n-1], i, n-1});
        for (int i = 0; i < k-1; i++) {
            auto [val, num, den] = pq.top(); pq.pop();
            den--;
            if (den > num) pq.push({(double)arr[num]/arr[den], num, den});
        }
        auto [val, num, den] = pq.top();
        return {arr[num], arr[den]};
    }
};
