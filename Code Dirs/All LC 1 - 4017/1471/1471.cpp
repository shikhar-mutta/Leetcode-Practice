// Link: https://leetcode.com/problems/the-k-strongest-values-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int m = arr[(arr.size() - 1) / 2];
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int da = abs(a - m), db = abs(b - m);
            if (da != db) return da > db;
            return a > b;
        });
        arr.resize(k);
        return arr;
    }
};
