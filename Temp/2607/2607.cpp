// Link: https://leetcode.com/problems/make-k-subarray-sums-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        int g = gcd(n, k);
        long long total = 0;

        for (int r = 0; r < g; r++) {
            vector<int> group;
            for (int i = r; i < n; i += g) group.push_back(arr[i]);
            sort(group.begin(), group.end());
            int median = group[group.size() / 2];
            for (int x : group) total += abs(x - median);
        }
        return total;
    }
};
