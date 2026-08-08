// Link: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long needSum = (long long)threshold * k;
        long long sum = 0;
        for (int i = 0; i < k; i++) sum += arr[i];
        int count = (sum >= needSum) ? 1 : 0;
        for (int i = k; i < (int)arr.size(); i++) {
            sum += arr[i] - arr[i-k];
            if (sum >= needSum) count++;
        }
        return count;
    }
};
