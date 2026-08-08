// Link: https://leetcode.com/problems/kth-missing-positive-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int missingBefore = arr[mid] - (mid + 1);
            if (missingBefore < k) lo = mid + 1;
            else hi = mid;
        }
        return lo + k;
    }
};
