// Link: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDel = arr[0], withDel = 0, best = arr[0];
        for (int i = 1; i < n; i++) {
            withDel = max(withDel + arr[i], noDel);
            noDel = max(noDel, 0) + arr[i];
            best = max({best, noDel, withDel});
        }
        return best;
    }
};
