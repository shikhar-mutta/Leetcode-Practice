// Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNonDecreasing(vector<int>& seq) {
        vector<int> tails;
        for (int x : seq) {
            auto it = upper_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return tails.size();
    }

    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int totalOps = 0;
        for (int start = 0; start < k; start++) {
            vector<int> seq;
            for (int i = start; i < n; i += k) seq.push_back(arr[i]);
            totalOps += (int)seq.size() - longestNonDecreasing(seq);
        }
        return totalOps;
    }
};
