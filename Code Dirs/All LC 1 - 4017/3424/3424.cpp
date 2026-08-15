// Link: https://leetcode.com/problems/minimum-cost-to-make-arrays-identical/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        long long noPermute = 0;
        for (int i = 0; i < n; i++) noPermute += llabs((long long)arr[i] - brr[i]);

        vector<int> a = arr, b = brr;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long permuteCost = k;
        for (int i = 0; i < n; i++) permuteCost += llabs((long long)a[i] - b[i]);

        return min(noPermute, permuteCost);
    }
};
