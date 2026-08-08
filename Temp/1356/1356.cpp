// Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int ca = __builtin_popcount(a), cb = __builtin_popcount(b);
            if (ca != cb) return ca < cb;
            return a < b;
        });
        return arr;
    }
};
