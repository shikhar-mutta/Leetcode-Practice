// Link: https://leetcode.com/problems/missing-number-in-arithmetic-progression/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        long long total = (long long)(arr[0] + arr[n-1]) * (n + 1) / 2;
        long long actual = 0;
        for (int x : arr) actual += x;
        return (int)(total - actual);
    }
};
