// Link: https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int need = m * k;
        if (need > n) return false;
        int count = 0;
        for (int i = m; i < n; i++) {
            if (arr[i] == arr[i - m]) {
                count++;
                if (count >= m * (k - 1)) return true;
            } else {
                count = 0;
            }
        }
        return false;
    }
};
